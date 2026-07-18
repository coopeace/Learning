tput bel
tput clear
echo "total number of column on screen = "
tput cols
echo "total number of rows on screen ="
tput lines
echo " This is a normal message"
tput blink
echo "This is a blinking message"
tput bold
echo "this is a bold message"
tput cup 10 20 # positions cursor at 10th row and 20th column
echo "Testing of tput\n"
tput smso # start stand out (bold) mode
echo "The bold has begun....."
tput rmso # end stand out (bold) mode
tput smul # start mode underline
echo " So also has underline"
tput rmul # end mode underline
