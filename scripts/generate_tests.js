const fs = require('fs');
const path = require('path');

const ROOT = path.join(__dirname, '..');
const SPEC_ROOT = process.env.CLEARHEAD_SPEC_DIR
  ? path.resolve(process.env.CLEARHEAD_SPEC_DIR)
  : path.resolve(ROOT, '..', 'specifications');

function loadTestDescriptions() {
  const registryPath = path.join(ROOT, 'test', 'test_descriptions.json');
  try {
    return JSON.parse(fs.readFileSync(registryPath, 'utf8'));
  } catch (error) {
    console.error(`Failed to read test descriptions: ${error.message}`);
    process.exit(1);
  }
}

for (const [category, tests] of Object.entries(loadTestDescriptions())) {
  const outputPath = path.join(ROOT, 'test', 'corpus', `${category}.txt`);
  let output = '';

  for (const [testName, test] of Object.entries(tests)) {
    const examplePath = path.join(SPEC_ROOT, test.source);
    const sexpPath = path.join(ROOT, 'test', 'trees', `${testName}.sexp`);

    if (!fs.existsSync(examplePath)) {
      console.error(`Registered specification fixture not found: ${examplePath}`);
      console.error('Set CLEARHEAD_SPEC_DIR to a specifications checkout.');
      process.exit(1);
    }
    if (!fs.existsSync(sexpPath)) {
      console.error(`Registered expected tree not found: ${sexpPath}`);
      process.exit(1);
    }

    const exampleContent = fs.readFileSync(examplePath, 'utf8').trim();
    const sexpContent = fs.readFileSync(sexpPath, 'utf8').trim();
    const separator = '='.repeat(test.description.length);
    output += `${separator}\n${test.description}\n${separator}\n${exampleContent}\n\n---\n\n${sexpContent}\n\n`;
  }

  fs.mkdirSync(path.dirname(outputPath), { recursive: true });
  fs.writeFileSync(outputPath, `${output.trim()}\n`);
  console.log(`Generated: ${path.relative(ROOT, outputPath)}`);
}

console.log('Test generation complete!');
