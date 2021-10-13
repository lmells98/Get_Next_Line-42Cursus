# Get_Next_Line-42

The project get_next_line, we are given the task to create a function that returns a new line read from a file descriptor. The bonus for this task seems intimidating at first. Funnily enough, trying to tackle the bonus part helped me in gaining an understanding on how the function operates logically.

There was a problem with the Moulinette checking system. The function prototype had changed recently, various students from my campus have had the same issue. Moulinette will not grade the bonus. Good chance that it had not been updated yet to meet the new requirements!

<img width="1189" alt="Screen Shot 2021-10-14 at 9 59 49 AM" src="https://user-images.githubusercontent.com/86273901/137226671-aa668b48-e10e-48b3-95a5-a00650df079c.png">

# How to use

Open a file to be read by using ```int fd = open("./text.txt", O_RDONLY)```

The ```get_next_line(fd)``` function takes in a file descriptor as a parameter. This function will return each new line read from a file descriptor, each time the function ```get_next_line(fd)``` is called.
