sudo make 
./main > result.cpp
echo "result code:"
cat ./result.cpp
g++ result.cpp -o result
echo "result:"
./result