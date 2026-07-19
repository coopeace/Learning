tput clear 
echo Enter the basic salary:
read basic_salary

allowance=$(echo "0.4*$basic_salary"|bc)
rent=$(echo "0.2*$basic_salary"|bc)
echo $allowance
