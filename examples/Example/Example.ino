/*
 * Example usage of the UnorderedMap library
 * This example demonstrates basic operations such as insertion, retrieval, and deletion using the UnorderedMap.
 */

#include <UnorderedMap.h> // Include the UnorderedMap library

// Create an UnorderedMap instance. KeyType and ValueType can be any type.
UnorderedMap<int, String> myMap;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial); // Wait for the serial port to connect. Needed for native USB port only.

  // Adding elements to the map
  myMap.put(1, "Apple");
  myMap.put(2, "Banana");
  myMap.put(3, "Cherry");

  // Retrieve and print elements
  Serial.println("Initial map contents:");
  // Check if a key exists
  if (myMap.contains(2)) {
    Serial.println("Map contains key 2.");
  }

  // Remove an element
  myMap.remove(2);
  Serial.println("After removing key 2:");


  // Access an element directly
  Serial.print("Value with key 1: ");
  Serial.println(myMap.getValue(1));

  // Clear the map
  myMap.clear();
  Serial.println("After clearing the map:");
  Serial.print("Map size: ");
  Serial.println(myMap.getSize());
}

void loop() {
  // Not used in this example
}