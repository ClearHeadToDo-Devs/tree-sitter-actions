const fs = require('fs');
const path = require('path');

function loadTestDescriptions() {
  try {
    return JSON.parse(fs.readFileSync('test/test_descriptions.json', 'utf8'));
  } catch (error) {
    console.error(`Failed to read test descriptions: ${error.message}`);
    process.exit(1);
  }
}

const testDescriptions = loadTestDescriptions();

// Process each test category
for (const [category, tests] of Object.entries(testDescriptions)) {
  const outputPath = path.join('test', 'corpus', `${category}.txt`);
  let output = '';
  
  for (const [testName, description] of Object.entries(tests)) {
    // Read the example file
    const examplePath = path.join('examples', `${testName}.actions`);
    const sexpPath = path.join('test', 'trees', `${testName}.sexp`);
    
    if (!fs.existsSync(examplePath)) {
      console.error(`Registered example file not found: ${examplePath}`);
      process.exit(1);
    }

    if (!fs.existsSync(sexpPath)) {
      console.error(`Registered expected tree not found: ${sexpPath}`);
      process.exit(1);
    }
    
    const exampleContent = fs.readFileSync(examplePath, 'utf8').trim();
    const sexpContent = fs.readFileSync(sexpPath, 'utf8').trim();
    
    // Generate the test case
    const testCase = `${'='.repeat(description.length)}
${description}
${'='.repeat(description.length)}
${exampleContent}

---

${sexpContent}

`;

    output += testCase;
  }

  // Corpus files are generated build artifacts, so the directory may not exist
  // in a fresh checkout.
  fs.mkdirSync(path.dirname(outputPath), { recursive: true });
  fs.writeFileSync(outputPath, output.trim() + '\n');
  console.log(`Generated: ${outputPath}`);
}

console.log('Test generation complete!');
