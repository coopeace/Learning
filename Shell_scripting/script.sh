#!/bin/bash

clear
echo Enter the Length:
read length
echo Enter the Breadth:
read breadth
echo Enter the Radius:
read radius

echo "Area of Rectangle:$(echo "$length*$breadth" | bc)"
echo "Perimeter of Rectangle:$(echo "2*($length+$breadth)" | bc)"
echo "Area of Circle:$(echo "3.14*$radius*$radius" | bc)"
echo "Circumference of Circle:$(echo "2*3.14*$radius" | bc)"
