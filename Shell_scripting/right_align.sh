echo "The number of columns :"
tput cols
width = tput cols
left = $width/3
echo "The number of rows :"
tput lines

tput cup $left 7
echo "choice"
