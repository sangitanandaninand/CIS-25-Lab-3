#!/bin/bash
set -e

echo "=== Compiling programs ==="
g++ -o TempLogger TempLogger.cpp
g++ -o TempAnalyzer TempAnalyzer.cpp
echo "✓ Compilation successful"

echo ""
echo "=== Running TempLogger ==="
./TempLogger < test_input.txt

echo ""
echo "=== Running TempAnalyzer ==="
./TempAnalyzer

echo ""
echo "=== Contents of temperatures.txt ==="
cat temperatures.txt
