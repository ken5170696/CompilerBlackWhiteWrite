
sudo make 
./main > result.c
echo "result code:"
cat ./result.c
g++ result.c -o result
echo "result:"
./result
echo ""
sudo make clean