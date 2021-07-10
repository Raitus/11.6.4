#include <iostream>
#include "string"

char encrypt_caesar(char symbol, int shift) {
  if (symbol < 'A' || symbol > 'Z' && symbol < 'a' || symbol > 'z'){

  }else {
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
}

char decrypt_caesar(char symbol, int shift) {
  return encrypt_caesar(encrypt_caesar(symbol, shift), -shift);
}

int main() {
  std::string text;
  int textShift=-27;

  std::cout << "Input text: " << std::endl;
  std::getline(std::cin, text);
  std::cout << "Input text shift: ";
  std::cin >> textShift;

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
