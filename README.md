# TNT Script used by Guoyi

The TNT script follows MIT and part of script is from setk.run belonging to Salvador Arias (Instituto Miguel Lillo, San Miguel de Tucumán, Argentina).

## Usage

- Place this script and your matrix tnt file `filename` under the folder that you call `tnt` or `exe` file is placed

- Enter `tnt`

- Enter command `guoyi filename;`

## Functions

- Extended implied weighting with K value setting (default, default K=12) or implighted weighting with K value setting (default K=12) or equal weighting.      

- Search trees via implicit enumeration (ntax<=25, but not for eiw) or TBR Mult (1000 times) (25<ntax<75, also for ntax<=25 with eiw) or Mult and Xmult (use random sectorial searches, produce 1,000 hits to best length and stop, 10 cycles of drifting, ratchet and fusing) (ntax>=75).      

- Perform Strict consensus / Majority-rule consensus / Half strict consensus.            

- Calculate jackknifing (1,000 times), bootstrap (1,000 times) and Relative Bremer support.

- Map apomorphic characters on the consensus tree.

- Calculate TL, CI, and RI. 

## Options

For Windows users

```
tnt run guoyi.run filename datatype weight 0/K cons resample prefix;
```

For Linux and Mac users

```
tnt run guoyi.run filename datatype weight K cons resample prefix,
```

- datatpye should be `32`, `dna`, `prot`, `num`  

  -  num=number, dna=DNA, prot=protein, 32=max number allowed (default)        

- weight should be `iw`, ew, `eiw`

  -  iw=implied weight, ew=equal weight, eiw=extended implied weight (default) N.B. ew must followed 0 (the K value position for ew iw and eiw)               

- K is 12 (default) following Goloboff et al. 2017 (Cladistics 34: 407–437)

  - it must more than 0 

- cons should be str, mjr, hlf  

  -  mjr=majority rule, hlf=half, str=strict (default)                   

- resample should be sum of what you want

  -  jak=1, boot=2, relative bremer=4 i.e. jak+boot+bremer=7 (default)       

- prefix can  be empty or a string

  - default is empty

## Results

- Results instructions are at the end of `tnt.log`.

- `trees.tre`, `resample.tre` are trees with taxname.

- `trees_no.tre`, `resample_no.tre` are trees without taxname.

- `winclada.tre` can be transferred to the acceptable format for WinClada by tnt2winclada and the output file can be put into Winclada with your tnt matrix file `filename` for mapping apomorphic characters and homoplasy.

## Cite

Cite this script is mandatory, list me (Guoyi Zhang) in your Acknowledgements is recommended.

# TNT2WinClada

```
~|~|\ |~|~  ~)  |    |o._ |~| _  _| _ 
 | | \| |   /_   \/\/ || ||_|(_|(_|(_|

MIT, Guoyi Zhang, 2023
```

## Function

Convert TNT output tree file without tags and taxname, e.g. `winclada.tre` produced by TNT script, to WinClada acceptable format tree.

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
