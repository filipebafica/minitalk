# minitalk
Data exchange program using UNIX signals

## 🗂 Table of Contents
* [About](#-about)
* [Getting Started](#-getting-started)
* [How to Use](#-how-to-use)
* [42 École | 42 São Paulo](#-42-école--42-são-paulo)

## 🧐 About
This is a pair of programs that communicate with each other using only UNIX signals.\
This project is part of 42 École/ 42 SP curriculum.\
Topics such as signals, and bitwise operations were addressed.

## 🏁 Getting Started
A Linux OS and the `gcc` compiler are needed.

#### ⚙️ Installing
To compile the code, clone the repo, and run the command `make`.
```
$ git clone https://github.com/filipebafica/minitalk.git
$ cd minitalk
$ make
```
This is going to generate two executables `server` and `client`.

## 🎈 How to Use
Run the `server`, you will see the process identifier (`pid`) displayed on the terminal.
```
./server
```
In another terminal, run the `client` passing the server's pid and a text.
```
./client <pid> "hello world"
```
You should be able to see the exact same text displayed on the server's terminal.

## 🏫 42 École | 42 São Paulo
42 École is a network of tech schools spread around the world where anyone can learn how to code for free.\
At 42 there are no teachers or classrooms, each student learns from and works with each other (peer-to-peer learning).\
To see more go to https://www.42.fr/ and https://www.42sp.org.br/.