/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student                                     #+#  #+#       #+#       */
/*                                                ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data original;
	original.id = 42;
	original.name = "forty-two";
	original.value = 42.42;

	std::cout << "=== Serialization Test ===" << std::endl;
	std::cout << std::endl;

	std::cout << "Original Data address : " << &original << std::endl;
	std::cout << "Original Data content : id=" << original.id
			  << " name=" << original.name
			  << " value=" << original.value << std::endl;
	std::cout << std::endl;

	/* Serialize: pointer -> uintptr_t */
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;
	std::cout << std::endl;

	/* Deserialize: uintptr_t -> pointer */
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized address  : " << deserialized << std::endl;
	std::cout << "Deserialized content  : id=" << deserialized->id
			  << " name=" << deserialized->name
			  << " value=" << deserialized->value << std::endl;
	std::cout << std::endl;

	/* Verify */
	if (deserialized == &original)
		std::cout << "\033[32m[OK] Pointers match!\033[0m" << std::endl;
	else
		std::cout << "\033[31m[KO] Pointers differ!\033[0m" << std::endl;

	return 0;
}
