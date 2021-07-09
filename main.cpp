#include <iostream>
#include "string"

char encrypt_caesar(char symbol, int shift) {
  if (symbol + shift < 'A') {
	return 'Z' + 1 + (symbol - 'A' + shift);
  } else if (symbol <= 'Z' && symbol + shift > 'Z') {
	return 'A' - 1 + (symbol - 'Z' + shift);
  } else if (symbol >= 'a' && symbol + shift < 'a') {
	return 'z' + 1 + (symbol - 'a' + shift);
  } else if (symbol + shift > 'z') {
	return 'a' - 1 + (symbol - 'z' + shift);
  } else {
	return symbol + shift;
  }
}

char decrypt_caesar(char symbol, int shift) {
  return encrypt_caesar(encrypt_caesar(symbol, shift), -shift);
}

int main() {
  std::string text;
  int textShift=-27;
  /*std::cout << "Input text shift: ";
  std::cin >> textShift;*/
  std::cout << "Input text: " << std::endl;
  std::getline(std::cin, text);
  for (int i = 0; i < text.length(); i++) {
	if (text[i] < 'A' || text[i] > 'Z' && text[i] < 'a' || text[i] > 'z') {
	  std::cout << "Symbol error, try again!";
	  return 1;
	}
  }
  if (textShift > 26 || textShift < -26) {
	textShift %= 26;
  }
  std::cout << "Encrypt: ";
  for (int symbol = 0; symbol < text.length(); symbol++) {
	std::cout << encrypt_caesar(text[symbol], textShift);
  }
  std::cout << std::endl << "Decrypt: ";
  for (int symbol = 0; symbol < text.length(); symbol++) {
	std::cout << decrypt_caesar(text[symbol], textShift);
  }
  return 0;
}
