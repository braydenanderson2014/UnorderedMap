# UnorderedMap for Arduino

`UnorderedMap` is a custom hash map implementation designed for Arduino projects that require efficient key-value pair storage. The class provides basic hash map functionalities such as insertion, retrieval, and deletion of elements.

## Features

- Templated class that can handle various data types for keys and values.
- Automatic resizing when the map reaches capacity.
- Duplicate key checking to prevent overwriting without explicit intent.
- Simple and intuitive API.

## Installation

To use `UnorderedMap` in your Arduino sketch:

1. Copy the `UnorderedMap.h` file to your project's directory.
2. Include `UnorderedMap.h` at the top of your sketch.

## Change Log
### Version 1.0.0
* Initial Release
### Version 1.0.1
* Added more documentation
* Removed UnorderedMap.cpp and moved all code to UnorderedMap.h
* Added Dynamic Resizing to UnorderedMap
* Added Duplicate check on set Function
### Version 1.0.2 
* Update to README
* Rebuilt library to utilize hashtable as its underlying structure. This allows for faster lookups and better memory usage
* This also means, since the Hashtable has already been tested, this library is considered stable and ready for use (except for maybe a few functions)
* Added a few more functions that Hashtable does not have.
### Version 1.0.3
* Modified the Constructor to take in a ```bool``` value to determine if the UnorderedMap should display debug messages. Default is ```false```
* Adjusted the ```remove``` function to return a ```bool``` value to determine if the key was found and removed or not... Since it calls for Hashtabes remove, it now properly calls the Hashtable remove function.
### Version 1.0.4
* Removed Debug Messages to save memory space, Will implement a version with debug messages later.
* Added Function Comments to all functions



## Usage

To create an `UnorderedMap`, specify the key and value data types when declaring an instance:

```cpp
#include "UnorderedMap.h"

UnorderedMap<String, int> myMap;
```
### Inserting Elements
```cpp
myMap.put("temperature", 25);
```
### Retrieving Elements
```cpp
int temperature;
if (myMap.get("temperature", temperature)) {
    // Use the temperature value
}
```
### Removing Elements
```cpp
if (myMap.remove("temperature")) {
    // Temperature was successfully removed
}
```
### Map Size and Empty Check
```cpp
size_t mapSize = myMap.getSize();

if (myMap.isEmpty()) {
    // Map is empty
}
```
## Common Methods
* insert: Add a key-value pair to the map. If the key already exists, its value is updated.
* get: Retrieve a value associated with a given key.
* remove: Remove a key-value pair from the map.
* getSize: Get the number of key-value pairs in the map.
* isEmpty: Check if the map is empty.

## Example
```cpp
#include "UnorderedMap.h"

UnorderedMap<String, int> myMap;

void setup() {
    Serial.begin(9600);
    myMap.insert("humidity", 60);
    myMap.insert("pressure", 1013);
}

void loop() {
    int humidity;
    if (myMap.contains("Humidity")) {
        Serial.print("Humidity: ");
        Serial.println(humidity);
    }
    delay(1000);
}
```
## Notes
This implementation is designed to be memory-efficient, which is critical for the constrained environment of Arduino devices.
The resize method will automatically be called when the map's capacity is exceeded, doubling the map's size.
Error handling for memory allocation failures is critical on Arduino, and the resize method includes a simple error message output to the serial monitor. This Library uses Hashtable as its its background magic. (This is a wrapper class)

## Contributing
Contributions to UnorderedMap are welcome. Please adhere to the provided coding standards and include unit tests with your pull requests.