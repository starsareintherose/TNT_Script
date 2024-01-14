# TNT2FigTree

```
~|~|\ |~|~~)|~o(~|~|~._ _ _
 | | \| | /_|~| _| | | }_}_

MIT, Guoyi Zhang, 2024
```

## Function

Convert TNT output tree file with resample tags, e.g. `resample.tre` produced by TNT script `guoyi.run`, to complete nexus format tree.

## Compile

### Linux & Unix

```
mkdir -p build && cd build
cmake ..
make && make install
```

### Windows

```
cl /EHsc tnt2figtree.cpp
```

## Usage

```
tnt2figtree ${input_file} ${output_file}
```

Interactive commands are also available.

```
tnt2figtree

~|~|\ |~|~~)|~o(~|~|~._ _ _
 | | \| | /_|~| _| | | }_}_
TNT2FigTree
MIT, Guoyi Zhang, 2024
please type help to see more commands

tnt2figtree> help
help			show interactive commands help
import <filename>	import a TNT output nexus format tree by TNT export command
export <filename>	export a nexus format tree file
quit			quit the program
exit			exit the program

tnt2figree>
```
