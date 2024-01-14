# TNT2WinClada

```
~|~|\ |~|~  ~)  |    |o._ |~| _  _| _ 
 | | \| |   /_   \/\/ || ||_|(_|(_|(_|

MIT, Guoyi Zhang, 2023
```

## Function

Convert TNT output tree file without tags and taxname, e.g. `winclada.tre` produced by TNT script `guoyi.run`, to WinClada acceptable format tree.

## Compile

### Linux & Unix

```
mkdir -p build && cd build
cmake ..
make && make install
```

### Windows

```
cl /EHsc tnt2winclada.cpp
```

## Usage

```
tnt2winclada -i ${input_file} -o ${output_file}
```

Interactive commands are also available.

```
tnt2winclada

~|~|\ |~|~  ~)  |    |o._ |~| _  _| _ 
 | | \| |   /_   \/\/ || ||_|(_|(_|(_|
TNT2WinClada
MIT, Guoyi Zhang, 2023
please type help to see more commands

tnt2winclada> help
help			show interactive commands help
input <filename>	input a TNT output tree from the specified file
output <filename>	output a winclada accessible tree file
quit			quit the program
exit			exit the program

tnt2winclada>
```
