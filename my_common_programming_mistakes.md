## Documenting my common programming errors to reduce the debugging time.

#### Missing semicolons
Missing semicolons at the end of multiple statements (including printf).  
Some lines lack the required semicolon terminator, which causes compilation errors.  
#### Missing braces in if statements
Braces {} are not used for some if blocks; this may cause logical errors if multiple statements are intended to be included.  
Several if statements lack explicit braces, making the code error‑prone when extending or modifying the block.  

#### Missing arithmetic operands.
Missing multiplication operand in arithmetic operation 2i, instead of 2*i.

#### Missing break statement
Missing break statement in one or more switch cases, causing unintended fall-through
