# Command Line Arguments

## Building
    g++ -o args main.cc

## Execution
    ./args <list of command line arguments>

## Example Usage
    $   g++ -o args main.cc    
    $   ./args first second third    
    argument values:
            argv[0] = ./args
            argv[1] = first
            argv[2] = second
            argv[3] = third

    argument count:
            argc = 4