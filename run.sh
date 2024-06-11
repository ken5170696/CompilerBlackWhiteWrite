
sudo make 
sudo chmod 777 *
./main > result.c
echo "result code:"
cat ./result.c
g++ result.c -o result
echo "result:"
sudo chmod 777 *
./result
echo ""
sudo make clean