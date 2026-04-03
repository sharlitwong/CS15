# test.sh
# Charlotte Wong (cwong22)
# March 28, 2026
# CS 15 Project 3 zap
#
# File purpose:
# diff tests stdout and decoded output files resulting from different
# inputs to ensure my implementation and the reference implementation
# of zap behave the same way

make clean && make zap

echo "=== TEST 1: No arguments ==="
if ./zap 2>&1 | grep -q "Usage"; then
    echo "PASSED"
else
    echo "FAILED"
fi

echo "=== TEST 2: Too few arguments ==="
if ./zap zap 2>&1 | grep -q "Usage"; then
    echo "PASSED"
else
    echo "FAILED"
fi

echo "=== TEST 3: Too many arguments ==="
if ./zap zap a.txt b.zap c.txt 2>&1 | grep -q "Usage"; then
    echo "PASSED"
else
    echo "FAILED"
fi

echo "=== TEST 4: Invalid command ==="
if ./zap blah a.txt b.zap 2>&1 | grep -q "Usage"; then
    echo "PASSED"
else
    echo "FAILED"
fi

echo "=== TEST 5: Bad input file ==="
if ./zap zap nonexistent.txt out.zap 2>&1 | grep -q "Unable to open file"; then
    echo "PASSED"
else
    echo "FAILED"
fi

echo "=== TEST 6: Empty file ==="
touch empty.txt
if ./zap zap empty.txt out.zap | grep -q "empty and cannot be compressed"; then
    echo "PASSED"
else
    echo "FAILED"
fi

echo "=== TEST 7: banana.txt roundtrip ==="
./zap zap banana.txt banana.zap
./zap unzap banana.zap banana_out.txt
if diff banana.txt banana_out.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, roundtrip mismatch"
fi

echo "=== TEST 8: stdout diff against reference (banana) ==="
./zap zap banana.txt banana.zap > my_out.txt 2>&1
./the_zap zap banana.txt banana_ref.zap > ref_out.txt 2>&1
if diff my_out.txt ref_out.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, stdout mismatch:"
    diff my_out.txt ref_out.txt
fi

echo "=== TEST 9: cross-decode banana (my encoder, ref decoder) ==="
./zap zap banana.txt banana.zap
./the_zap unzap banana.zap banana_cross.txt
if diff banana.txt banana_cross.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, cross-decode mismatch"
fi

echo "=== TEST 10: sentences.txt roundtrip ==="
./zap zap sentences.txt sentences.zap
./zap unzap sentences.zap sentences_out.txt
if diff sentences.txt sentences_out.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, roundtrip mismatch"
fi

echo "=== TEST 11: stdout diff against reference (sentences) ==="
./zap zap sentences.txt sentences.zap > my_out.txt 2>&1
./the_zap zap sentences.txt sentences_ref.zap > ref_out.txt 2>&1
if diff my_out.txt ref_out.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, stdout mismatch:"
    diff my_out.txt ref_out.txt
fi

echo "=== TEST 12: shakespeare roundtrip ==="
./zap zap works_of_shakespeare.txt shakes.zap
./zap unzap shakes.zap shakes_out.txt
if diff works_of_shakespeare.txt shakes_out.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, roundtrip mismatch"
fi

echo "=== TEST 13: stdout diff against reference (shakespeare) ==="
./zap zap works_of_shakespeare.txt shakes.zap > my_out.txt 2>&1
./the_zap zap works_of_shakespeare.txt shakes_ref.zap > ref_out.txt 2>&1
if diff my_out.txt ref_out.txt > /dev/null; then
    echo "PASSED"
else
    echo "FAILED, stdout mismatch:"
    diff my_out.txt ref_out.txt
fi

echo '=== TEST 14: bad_zap_file ==='
if ./zap unzap bad_zap_file out.txt 2>&1 | grep -q "Encoding did not match Huffman tree"; then
    echo "PASSED"
else
    echo "FAILED"
fi

