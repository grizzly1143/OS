for ((i = 0; i < 2000; i++)) do
value=$(tail -1 input.txt)
num=$(expr $value + 1)
echo $num>>input.txt
done
