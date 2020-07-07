# FASTAtools :scroll:

A set of functions to handle FASTA format file for DNA analysis.

## Goals

The main goal of the project is to implement a set of functions to manage DNA sequences exploitation in C programming.

### **Features** :dart:

- [x] Manage and display a FASTA file with the following format for all the files [1]
    *>identifiers*
    *DNA SEQUENCES*

- [x] RNA display from all the sequences defined in the FASTA file [2]

- [x] Determinate and display the reverse complement of the sequences defined in the FASTA file [3]

- [x] K-mers display is also available for the given sequence [4]

- [ ] Display and manage the coding sequence available for the given FASTA file [5]

- [ ] Display and manage the amino acids which refer to coding sequence available in the given FASTA file [6]

- [ ] Manage the arrangement of the FASTA file to make more easy the DNA sequences analysis [7]

### **Usage** :construction_worker:

Compilation is doing by using the make command. Make sure you got it before:

    $>make
It will compile all the project and generate the binary executable file named *FASTAtools*.
All the features listed above are available with a specific options given in parameter to the *FASTAtools* binary. The FASTA file can be load from a file of simply be manually written in the standard input of the program.

    $>./FASTAtools 1 < ex.fasta

For example by doing this, you will load on the standard input the ex.fasta file which will be treated with the [1] option. All the reference to the options are listed in the [Features](#features-dart) above.

### **Technical purpose and difficulties** :pushpin:
I have to work on memory leak and make more efficient the algorithm I used int the project.
So memory leaks are my first trouble.

>:bulb: For Epitech students, It cover 71.5% of Nao Marvin's tests.
