# Huffman Encoding

This project implements Huffman Encoding, a data compression algorithm that is used to reduce the size of data by assigning shorter codes to frequently occurring characters. It utilizes a priority queue and a binary tree to build a variable-length prefix code for each character in the input string.

## Features

- Count the frequency of characters in the input string.
- Build a Huffman tree based on the character frequencies.
- Generate a lookup table of characters and their corresponding Huffman codes.
- Encode a given string using Huffman codes.
- Decode a given bit sequence using the Huffman tree.

## Getting Started

### Prerequisites

To run this project, you need to have a C++ compiler installed on your machine.

### Installation

1. Clone the repository:

   ```shell
   git clone https://github.com/your-username/huffman-encoding.git
   ```

2. Compile the source code:

   ```shell
   g++ huffman_encoding.cpp -o huffman_encoding
   ```

### Usage

1. Run the executable:

   ```shell
   ./huffman_encoding
   ```

2. Enter the string you want to encode when prompted.

3. The program will display the Huffman codes for each character in the input string, followed by the encoded string.

4. The program will then decode the encoded string and display the original string.

## Example

```
Enter the string to be encoded: hello
HUFFMAN CODE:
e: 0
l: 10
h: 110
o: 111

Encoded String: 1100101111
Decoded String: hello
```

## Contributing

Contributions are welcome! If you find any issues or want to add new features, feel free to open a pull request.
