basename "$PWD"
g++ -fsanitize=address --std=c++17 -o program *.cpp || exit
files=$(ls *.in)
for file in $files; do
    name="${file%.*}"
    echo "$name running"
    ./program < "$file" > "/tmp/$name.out" || { echo "!! crashed"; exit; }
    diff -y "/tmp/$name.out" "$name.ans" || { echo "!! failed"; exit; }
done