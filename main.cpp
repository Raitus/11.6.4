#include <iostream>
#include "string"

std::string encrypt_caesar(std::string text, int shift) {
  std::string temp;
  for (char symbol : text) {
	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
	  if (symbol + shift < 'A') {
		temp += 'Z' + 1 + (symbol - 'A' + shift);
	  } else if (symbol <= 'Z' && symbol + shift > 'Z') {
		temp += 'A' - 1 + (symbol - 'Z' + shift);
	  } else if (symbol >= 'a' && symbol + shift < 'a') {
		temp += 'z' + 1 + (symbol - 'a' + shift);
	  } else if (symbol + shift > 'z') {
		temp += 'a' - 1 + (symbol - 'z' + shift);
	  } else {
		temp += symbol + shift;
	  }
	}
  }
  return temp;
}

void decrypt_caesar(std::string text, int shift) {
  std::cout << encrypt_caesar(text, -shift);
}

int main() {
  std::string text;
  int textShift;
  std::cout << "Input text shift: ";
  std::cin >> textShift;
  std::cin.ignore(INT_MAX, '\n');
  std::cout << "Input text: ";
  std::getline(std::cin, text);

  if (std::abs(textShift) > 26) {
	textShift %= 26;
  }

  std::cout << "Encrypt: ";
  text = encrypt_caesar(text, textShift);
  std::cout << text;
  std::cout << std::endl << "Decrypt: ";
  decrypt_caesar(text, textShift);
  return 0;
}
