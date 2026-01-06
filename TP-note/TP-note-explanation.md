# TP-note Code Explanation

## Project Overview

The TP-note project is a C++ implementation of a network infrastructure management system. It demonstrates advanced object-oriented programming concepts including inheritance, polymorphism, virtual functions, and template metaprogramming. The system models various types of network devices (routers, switches, servers) and provides an infrastructure class to manage collections of these devices.

The codebase is organized into header files (`.hpp`) in the `include/` directory and implementation files (`.cpp`) in the `src/` directory, following standard C++ project structure. It utilizes the Standard Template Library (STL) for containers, algorithms, and utilities.

## Class Hierarchy and Relationships

The project features a multi-level inheritance hierarchy:

```
Class (reference counting)
  └── Base (abstract, printing interface)
      ├── NetworkDevice (generic network device)
      │   ├── Router (specialized device with routing table)
      │   ├── Switch (specialized device with ports)
      │   └── Server (specialized device with CPU cores)
      ├── NetworkInfrastructure (device collection manager)
      └── KNN<T> (template class for K-Nearest Neighbors algorithm)
```

### Key Relationships:
- `Class` provides reference counting for all derived classes
- `Base` defines the printing interface with pure virtual `PrintOn()` method
- `NetworkDevice` is the base class for all network equipment types
- `NetworkInfrastructure` manages pointers to `NetworkDevice` objects
- `KNN<T>` is a separate template class not directly integrated with the network classes

## Detailed Explanation of Classes

### Class

**Purpose**: Provides reference counting functionality for tracking object instances.

**Key Features**:
- Static member `ref` to count total instances
- Constructor increments counter
- Copy constructor increments counter  
- Destructor decrements counter
- Static method `GetRef()` returns current count

**Implementation**: Simple reference counting mechanism, likely for debugging or memory management purposes.

### Base

**Purpose**: Abstract base class defining the printing interface.

**Key Features**:
- Pure virtual method `PrintOn(std::ostream &)` for polymorphic printing
- Friend function `operator<<(std::ostream &, const Base &)` for stream output
- Inherits from `Class` for reference counting

**Implementation**: Enables polymorphic output through virtual functions.

### NetworkDevice

**Purpose**: Represents a generic network device with common attributes and operations.

**Attributes**:
- `hostname`: Device name
- `ipAddress`: IP address string
- `location`: Physical location
- `vendor`: Manufacturer
- `osVersion`: Operating system version
- `year`: Installation year
- `powerConsumption`: Power usage in watts
- `isCritical`: Criticality flag

**Key Methods**:
- Multiple constructors (default, parameterized, copy)
- Assignment operator
- Getters and setters for all attributes
- `ping()`: Displays hostname and IP
- `printInfo()`: Detailed device information output
- `PrintOn()`: Virtual printing method

**Implementation**: Provides comprehensive device management with proper copy semantics.

### Router

**Purpose**: Specialized network device representing a router.

**Additional Attributes**:
- `routingTableSize`: Number of routes in routing table

**Key Features**:
- Inherits all `NetworkDevice` functionality
- Overrides `printInfo()` and `PrintOn()` to include routing table size
- Specific constructor accepting routing table size

### Switch

**Purpose**: Specialized network device representing a network switch.

**Additional Attributes**:
- `portCount`: Number of network ports

**Key Features**:
- Inherits all `NetworkDevice` functionality
- Overrides `printInfo()` and `PrintOn()` to include port count
- Specific constructor accepting port count

### Server

**Purpose**: Specialized network device representing a server.

**Additional Attributes**:
- `cpuCores`: Number of CPU cores

**Key Features**:
- Inherits all `NetworkDevice` functionality
- Overrides `printInfo()` and `PrintOn()` to include CPU cores
- Specific constructor accepting CPU core count

### NetworkInfrastructure

**Purpose**: Manages a collection of network devices with advanced operations.

**Attributes**:
- `name`: Infrastructure name
- `maxDevices`: Maximum capacity
- `devices`: Vector of `NetworkDevice*` pointers

**Key Methods**:
- Constructors (default, parameterized, copy)
- Assignment operator
- Getters/setters for attributes
- `addDevice()`: Adds device if capacity allows and hostname unique
- `removeDeviceByHostname()`: Removes device by hostname
- `searchDeviceByHostname()`: Binary search for device (O(log n))
- `listDevices()`: Displays all device hostnames
- `averagePowerConsumptionByType()`: Calculates average power usage by device type
- `sortAndUniqueDevices()`: Private method maintaining sorted unique devices by hostname

**Implementation**: Uses STL algorithms for sorting, searching, and unique operations. Implements binary search for efficient lookups.

### KNN<T>

**Purpose**: Template class implementing K-Nearest Neighbors algorithm framework.

**Attributes**:
- `k`: Number of neighbors to find

**Key Methods**:
- `getK()`: Returns k value
- `findNearestNeighbors()`: Finds k closest neighbors using similarity measure
- `similarityMeasure()`: Pure virtual method for distance/similarity calculation

**Implementation**: Template allows use with any data type T. The `findNearestNeighbors` method computes distances for all training data points, sorts by distance, and returns indices of k nearest neighbors.

## Main Program Flow

The `main.cpp` file demonstrates the system's capabilities:

1. **Device Creation and Configuration**:
   - Creates `NetworkDevice` instances with default and parameterized constructors
   - Demonstrates setter methods for property configuration
   - Shows `ping()` and `printInfo()` methods

2. **Specialized Device Usage**:
   - Creates `Router`, `Switch`, and `Server` objects
   - Sets device-specific attributes (routing table size, port count, CPU cores)
   - Displays specialized information

3. **Infrastructure Management**:
   - Creates `NetworkInfrastructure` with name and capacity
   - Adds devices to infrastructure
   - Lists all devices
   - Performs binary search for specific hostname
   - Calculates average power consumption by device type
   - Demonstrates device removal

## Special Features and Algorithms

### Binary Search Implementation
The `searchDeviceByHostname()` method implements binary search on the sorted device list, achieving O(log n) lookup time.

### Dynamic Type Identification
The `averagePowerConsumptionByType()` method uses `dynamic_cast` to identify device types at runtime for statistical calculations.

### Unique Device Management
The infrastructure ensures no duplicate hostnames through the `sortAndUniqueDevices()` method, which removes duplicates and maintains sorted order.

### Template Metaprogramming
The `KNN` class demonstrates template usage for generic algorithm implementation.

## Conclusion

This TP-note project showcases comprehensive C++ programming skills including:
- Object-oriented design with multiple inheritance levels
- Polymorphism through virtual functions
- Template programming for generic algorithms
- STL container and algorithm usage
- Memory management with pointers
- Exception-safe copy operations
- Efficient search algorithms

The code demonstrates practical application of network device management concepts while adhering to C++ best practices for class design, inheritance, and polymorphism. The inclusion of the KNN template class suggests potential for extending the system with machine learning capabilities for network analysis.