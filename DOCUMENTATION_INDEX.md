# Documentation Index

**Last Updated:** 2025-11-04 (Phase 2 Complete)

This index helps you find the right documentation for your needs.

---

## I want to...

### ...understand what this parser does
→ **[README.md](./README.md)** - Overview and quick start

### ...use the parser in my project
→ **[CLAUDE.md](./CLAUDE.md)** - Developer guide with examples

### ...understand the architecture
→ **[ARCHITECTURE.md](./ARCHITECTURE.md)** - Complete technical details

### ...understand the file format
→ **[docs/action_specification.md](./docs/action_specification.md)** - Format specification

### ...see the project plan
→ **[ROADMAP.md](./ROADMAP.md)** - Development phases and timeline

### ...check current status
→ **[PROGRESS.md](./PROGRESS.md)** - What's done, what's next

### ...add a new property
→ **[CLAUDE.md#adding-a-new-property](./CLAUDE.md#adding-a-new-property)** - Step-by-step guide

### ...modify existing syntax
→ **[CLAUDE.md#modifying-existing-syntax](./CLAUDE.md#modifying-existing-syntax)** - Workflow

### ...integrate with CLI
→ **[ARCHITECTURE.md#cli-integration](./ARCHITECTURE.md#cli-integration)** - Rust type generation

### ...understand why we chose this approach
→ **[docs/archive/ARCHITECTURE_DECISION.md](./docs/archive/ARCHITECTURE_DECISION.md)** - Decision rationale

---

## Documentation by Role

### For Developers

**Getting started:**
1. [CLAUDE.md](./CLAUDE.md) - How to use and develop
2. [ARCHITECTURE.md](./ARCHITECTURE.md) - How it works

**Day-to-day:**
- Add property: Edit `parser-ontology.ttl`, run `npm run generate`
- Test: `tree-sitter parse examples/*.actions`
- Debug: Check `syntax_mapping.json` and `grammar-generated.js`

### For Architects

**System design:**
1. [ARCHITECTURE.md](./ARCHITECTURE.md) - Full technical architecture
2. [ROADMAP.md](./ROADMAP.md) - Project phases
3. [docs/archive/ARCHITECTURE_DECISION.md](./docs/archive/ARCHITECTURE_DECISION.md) - Why this approach

**Integration:**
- CLI: [ARCHITECTURE.md#cli-integration](./ARCHITECTURE.md#cli-integration)
- Ontology: [parser-ontology.ttl](./parser-ontology.ttl)

### For Users

**File format:**
1. [docs/action_specification.md](./docs/action_specification.md) - What you can write
2. [examples/](./examples/) - Real examples

**Tools:**
- Neovim: Coming in Phase 5
- CLI: See `../clearhead-cli/`

### For Maintainers

**Status tracking:**
1. [PROGRESS.md](./PROGRESS.md) - Current state
2. [ROADMAP.md](./ROADMAP.md) - What's next
3. [PHASE2_COMPLETE.md](./PHASE2_COMPLETE.md) - Latest milestone

**Architecture:**
- [ARCHITECTURE.md](./ARCHITECTURE.md) - Reference
- [docs/archive/](./docs/archive/) - Historical decisions

---

## Documents by Category

### Core Documentation

| Document | Purpose | Audience |
|----------|---------|----------|
| [README.md](./README.md) | Project overview | Everyone |
| [CLAUDE.md](./CLAUDE.md) | Developer guide | Developers |
| [ARCHITECTURE.md](./ARCHITECTURE.md) | Technical architecture | Architects, Developers |

### Specifications

| Document | Purpose | Audience |
|----------|---------|----------|
| [docs/action_specification.md](./docs/action_specification.md) | File format spec | Users, Developers |
| [docs/actions-fileformat-spec.md](./docs/actions-fileformat-spec.md) | Detailed syntax | Developers |
| [parser-ontology.ttl](./parser-ontology.ttl) | Syntax annotations | Developers |

### Project Management

| Document | Purpose | Audience |
|----------|---------|----------|
| [ROADMAP.md](./ROADMAP.md) | Development phases | Everyone |
| [PROGRESS.md](./PROGRESS.md) | Current status | Maintainers |
| [PHASE2_COMPLETE.md](./PHASE2_COMPLETE.md) | Milestone details | Developers |

### Archive

| Document | Purpose | Audience |
|----------|---------|----------|
| [docs/archive/ARCHITECTURE_DECISION.md](./docs/archive/ARCHITECTURE_DECISION.md) | Why current approach | Architects |
| [docs/archive/ARCHITECTURE_REVIEW.md](./docs/archive/ARCHITECTURE_REVIEW.md) | Comparison analysis | Architects |
| [docs/archive/APPROACH_EVALUATION.md](./docs/archive/APPROACH_EVALUATION.md) | Detailed evaluation | Architects |

---

## What to Edit vs What's Generated

### Edit These (Source Files)

- `parser-ontology.ttl` - Syntax definitions
- `grammar.js` - Structure and utilities
- `src/grammar_generator.js` - Generation logic
- `scripts/generate-syntax-mapping.js` - Ontology parser
- `examples/*.actions` - Test files
- All `*.md` documentation

### DON'T Edit These (Generated)

- `syntax_mapping.json` - Run `npm run generate:mapping`
- `grammar-generated.js` - Run `npm run generate:grammar`
- `src/parser.c` - Run `tree-sitter generate`
- `src/node-types.json` - Run `tree-sitter generate`
- `actions.so` - Run `tree-sitter build`

---

## Documentation Workflow

### When Adding a Feature

1. Update `parser-ontology.ttl`
2. Run `npm run generate && npm run build:parser`
3. Add example to `examples/`
4. Test with `tree-sitter parse`
5. Update `PROGRESS.md` if milestone

### When Making Architecture Changes

1. Update [ARCHITECTURE.md](./ARCHITECTURE.md)
2. Update [ROADMAP.md](./ROADMAP.md) if affects plans
3. Add decision record to `docs/archive/` if significant
4. Update [CLAUDE.md](./CLAUDE.md) if affects developers

### When Completing a Phase

1. Update [PROGRESS.md](./PROGRESS.md)
2. Create milestone document (like `PHASE2_COMPLETE.md`)
3. Update [ROADMAP.md](./ROADMAP.md) status
4. Update [README.md](./README.md) status

---

## External References

- [Tree-Sitter Documentation](https://tree-sitter.github.io/tree-sitter/)
- [Jakobeha/type-sitter](https://github.com/Jakobeha/type-sitter) - Rust type generation
- [V3 Ontology](https://clearhead.us/vocab/actions/v3) - Domain concepts
- [Platform ARCHITECTURE.md](../ARCHITECTURE.md) - Overall platform

---

## Quick Reference

### Commands

```bash
# Generate
npm run generate                 # mapping + grammar
npm run generate:mapping         # just mapping
npm run generate:grammar         # just grammar

# Build
npm run build:parser            # compile parser

# Test
tree-sitter parse FILE          # parse one file
tree-sitter parse --debug FILE  # debug parsing
npm test                        # run test suite
```

### File Locations

```
parser-ontology.ttl              # Edit: syntax definitions
syntax_mapping.json              # Generated: intermediate
grammar-generated.js             # Generated: rules
grammar.js                       # Edit: structure
src/parser.c                     # Generated: C code
src/node-types.json              # Generated: AST types
examples/*.actions               # Edit: test files
```

---

**Status:** Phase 2 Complete
**Next:** Phase 3 - Testing
**Questions?** Start with [CLAUDE.md](./CLAUDE.md)
