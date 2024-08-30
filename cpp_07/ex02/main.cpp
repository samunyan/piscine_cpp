/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:54:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/24 19:54:34 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "colors.hpp"
#include <iomanip>
#include <iostream>
#include <string>

#define MAX_VAL 10

static void testIntArr();
static void testStringArr();

int main() {
  testIntArr();
  testStringArr();
  return 0;
}

static void printTestName(const std::string &name) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << name << RESET_ALL << std::endl;
}

static void printSubTestName(const std::string &name) {
  std::cout << BG_LGRAY << name << RESET_ALL << std::endl;
}

static void testIntArr() {
  try {
    printTestName("Array<int> constructor with no parameter");
    Array<int> arr;
    std::cout << "Array has " << arr.size() << " elements" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<int> constructor with size parameter == 10");
    Array<int> arr(MAX_VAL);
    std::cout << "Array has " << arr.size() << " elements" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<int> copy constructor");
    Array<int> arr(MAX_VAL);
    fillArray(arr);
    Array<int> tmp(arr);

    printSubTestName("Checking values");
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in original");
    arr[0] = 42;
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in copy");
    tmp[0] = -42;
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<int> Assignment operator");
    Array<int> arr(MAX_VAL);
    fillArray(arr);
    Array<int> tmp;
    tmp = arr;

    printSubTestName("Checking values");
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in original");
    arr[0] = 42;
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in copy");
    tmp[0] = -42;
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<int> [] operator");
    Array<int> arr(MAX_VAL);
    fillArray(arr);
    for (unsigned int i(0); i < arr.size(); ++i) {
      std::cout << "Value at index " << i << ": " << arr[i] << std::endl;
    }
    printTestName("const Array<std::int> [] operator with index out of bounds");
    const Array<int> arrConst(arr);
    for (unsigned int i(0); i < arrConst.size() + 1; ++i) {
      std::cout << "Value at index " << i << ": " << arr[i] << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}

static void testStringArr() {
  try {
    printTestName("Array<std::string> constructor with no parameter");
    Array<std::string> arr;
    std::cout << "Array has " << arr.size() << " elements" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<std::string> constructor with size parameter == 10");
    Array<std::string> arr(MAX_VAL);
    std::cout << "Array has " << arr.size() << " elements" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<std::string> copy constructor");
    Array<std::string> arr(MAX_VAL);
    fillArray(arr);
    Array<std::string> tmp(arr);

    printSubTestName("Checking values");
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in original");
    arr[0] = "change_original";
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in copy");
    tmp[0] = "change_copy";
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<std::string> Assignment operator");
    Array<std::string> arr(MAX_VAL);
    fillArray(arr);
    Array<std::string> tmp;
    tmp = arr;

    printSubTestName("Checking values");
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in original");
    arr[0] = "change_original";
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

    printSubTestName("Changing value in copy");
    tmp[0] = "change_copy";
    std::cout << "Original at index 0: " << arr[0] << std::endl;
    std::cout << "Copy at index 0: " << tmp[0] << std::endl;

  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  try {
    printTestName("Array<std::string> [] operator");
    Array<std::string> arr(MAX_VAL);
    fillArray(arr);
    for (unsigned int i(0); i < arr.size(); ++i) {
      std::cout << "Value at index " << i << ": " << arr[i] << std::endl;
    }
    printTestName(
        "const Array<std::string> [] operator with index out of bounds");
    const Array<std::string> arrConst(arr);
    for (unsigned int i(0); i < arrConst.size() + 1; ++i) {
      std::cout << "Value at index " << i << ": " << arr[i] << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}
