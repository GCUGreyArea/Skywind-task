# Simple number parser

## BNF for valid input

```bash
Input                  ::= <Start> <DeliminatorList> <End> <NumberList>
Start                  ::= '//'
DeliminatorList        ::= <SimpleDeliminator> || 1
SimpleDeliminator      ::= [0-9A-Za-z\,\-\.\*\&\^\%\$\£\@\!\+]+
ComplexDeliminatorList ::= '[' <SimpleDeliminator> ']' || '[' <SimpleDeliminator> ']' <ComplexDeliminatorList>
End                    ::= '\n'
NumberList             ::= [0-9]+ || [0-9]+ <SimpleDeliminator> <NumberList>
```

### Building the project

The project has been designed and tested on MacOS but should build and function correctly on Linux. If you are running Windows 10 or 11 please build this project in WSL2 using the latest Ubuntu distro.

```bash




### Dependencies

1. Google test framework
2. Google benchmark framework
