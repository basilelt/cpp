BUILD_DIR = build
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include/
TARGET = main
SRCS = $(wildcard src/*.cpp)
OBJS = $(notdir $(SRCS:.cpp=.o))

$(TARGET): $(addprefix $(BUILD_DIR)/, $(OBJS))
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(addprefix $(BUILD_DIR)/, $(OBJS))
	chmod +x $(TARGET)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean