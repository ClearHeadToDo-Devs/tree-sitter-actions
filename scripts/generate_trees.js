const fs = require('fs');
const path = require('path');
const { spawnSync } = require('child_process');

// Get all example files
const examplesDir = path.join(__dirname, '..', 'examples');
const treesDir = path.join(__dirname, '..', 'test', 'trees');

const exampleFiles = fs.readdirSync(examplesDir)
  .filter(f => f.endsWith('.actions'))
  .sort();

console.log('Generating tree files from examples...\n');

for (const exampleFile of exampleFiles) {
  const baseName = path.basename(exampleFile, '.actions');
  const examplePath = path.join(examplesDir, exampleFile);
  const treePath = path.join(treesDir, `${baseName}.sexp`);

  const result = spawnSync('tree-sitter', ['parse', '--no-ranges', examplePath], {
    encoding: 'utf8',
    cwd: path.join(__dirname, '..')
  });

  // Parse errors are valid expected trees for negative grammar tests. A real
  // invocation failure has no source tree and must still fail regeneration.
  if (!result.stdout.includes('(source_file')) {
    console.error(`✗ Failed to generate: ${baseName}.sexp`);
    console.error(result.stderr || result.stdout);
    process.exit(1);
  }

  const cleanedOutput = result.stdout
    .trim()
    .replace(/\n[^\n]*\tParse:.*$/, '')
    .trim();

  fs.writeFileSync(treePath, cleanedOutput);
  console.log(`✓ Generated test/trees/${baseName}.sexp`);
}

console.log('\nTree generation complete!');
