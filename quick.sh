#!/bin/bash

# Quick test script - minimal output
make clean && make MetroSim && \
./MetroSim stations.txt my_output.txt test_commands.txt > my_stdout.txt && \
./the_MetroSim stations.txt ref_output.txt test_commands.txt > ref_stdout.txt && \
echo "=== STDOUT DIFF ===" && diff my_stdout.txt ref_stdout.txt && \
echo "=== OUTPUT FILE DIFF ===" && diff my_output.txt ref_output.txt && \
echo "✓ All tests passed!" || echo "✗ Tests failed - see diffs above"