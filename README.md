# DataStruct-Mini-Project

Nama: Maulana Anugra Putra

NRP: 5025251159

# A. Stack Browser History (stack.c)
This program simulates a browser history system using a stack data structure, which follows the Last In, First Out (LIFO) principle. Each time a user visits a new webpage, the URL is pushed onto the stack, making it the current page at the top. When the user presses the back button, the program pops the top element, effectively removing the most recently visited page and returning to the previous one. The program also allows users to view the current page using a peek operation and display the full browsing history from most recent to oldest.

This is how the program looks like:

<img width="1242" height="299" alt="Screenshot 2026-03-24 224627" src="https://github.com/user-attachments/assets/4bdb06e5-9614-4763-b147-862eea91f42e" />

When run, it outputs a browser menu like shown in the image. Here, the user can choose between 5 actions. After an action is done, it will go back to this starting menu. This will loop until the user decides to exit the program (which is action no. 0) which will break the loop and end the program. Here's the list that the user can do:

1. Visiting a webpage
   
   This action allows the user to visit a webpage. This is the PUSH function for the stack concept.

   <img width="372" height="268" alt="Screenshot 2026-03-24 225126" src="https://github.com/user-attachments/assets/d71ad3fc-a253-43b2-8173-1c2575faf364" />

When option 1 is chosen, it will tell the user to input the webpage like shown in the image. It will then shows that it have visited the webpage after the user types in the webpage.

<img width="392" height="293" alt="Screenshot 2026-03-24 225140" src="https://github.com/user-attachments/assets/cf4a168e-4abc-4ccd-853d-894a5c604bdf" />

The program can only hold up to 10 webpages active at a time, so if there's already 10 webpages open and the user tries to visit another webpage again, this will happen:

<img width="409" height="293" alt="image" src="https://github.com/user-attachments/assets/adfd2643-2e58-41e1-9940-baaf7be5d6b8" />

2. Go back to the previous webpage
   
   This action allows the user to go back to a previous webpage that the user has visited before. This is the POP function for the stack concept. When chosen, it will output a text saying that you're leaving the webpage that you're currently on, and the previous webpage will be the newly current active webpage. In this example I'm currently on github.com, and the previous webpage was youtube.com.

   <img width="435" height="289" alt="image" src="https://github.com/user-attachments/assets/24b5e12d-2d83-41a9-a805-91148a6325c0" />

   If the user doesn't have any webpages active (if the stack is empty), then it will output an error:

   <img width="390" height="262" alt="image" src="https://github.com/user-attachments/assets/efc66603-ce92-44b2-89ea-c251bf1052bc" />

4. Shows which webpage is the user currently on
   
   This action allows the user to check or peek what webpage are they currently on. How this works is that it checks the very recently opened webpage in the stack (or the topmost webpage in the stack) and it will output text that will tell the user what webpage are they currently on.

   <img width="365" height="275" alt="image" src="https://github.com/user-attachments/assets/cd53ce2f-d695-4556-b6c1-35125aaade5b" />

If there is no webpages active, then it will output:

<img width="411" height="271" alt="image" src="https://github.com/user-attachments/assets/9c94887f-30d3-42e5-9079-e102af6871a0" />

4. Shows the list of all active webpages
   
   This action allows the user to check all of the webpages that are still in the stack. The stack can only hold up to 10 webpages at a time, so it can only show up to 10.

   <img width="400" height="908" alt="image" src="https://github.com/user-attachments/assets/49a3e0c0-a44e-4777-9475-a27f3c76a430" />

6. Exit the program
   
   This action allows the user to exit the program if they're already finished using the program. This action can be done at any time, doesn't matter if the stack is empty or not. When the user inputs this action, it will break the loop and end the program.

   <img width="984" height="324" alt="image" src="https://github.com/user-attachments/assets/9e291cff-85c6-4911-b35f-3843cdced137" />

# B. Queue Ticket Counter (queue.c)
This program simulates a real-life ticket counter system using a queue data structure, where customers are served in the exact order they arrive, following the FIFO (First In, First Out) principle. Users interact with the program through a menu, allowing them to add customers to the line using the enqueue operation, remove customers when they are served using the dequeue operation, check who is next in line with a peek operation, and display the full queue. Internally, the program uses an array along with front, rear, and count variables to efficiently manage the queue, including circular indexing to reuse space when elements are removed. This directly reflects how queues function in computer science and real-world systems, ensuring fairness by always serving the earliest arriving customer first.

This is how the program looks like:

<img width="434" height="232" alt="image" src="https://github.com/user-attachments/assets/ce004011-6e01-4c05-b178-3841e0999338" />

Similar to the first program, it outputs a menu where the user can pick which action to do. This is what each action does:

1. Join in the line (Enqueue)
   This action allows the user to input a name to make it join the queue. Each name that is inputted using this action will be indicated as "rear", and with each new name added to the queue, the "rear" indicator is moved to the recently added name, to ensure that every time a new name is added, it will always be put on behind the last person that has entered the queue before so the queue won't be interrupted.

<img width="657" height="1194" alt="image" src="https://github.com/user-attachments/assets/ae66d128-b646-4bdb-be07-b3de08ddcbda" />

This is an example of an user inputting 4 names on the queue.

2. Serve the customers waiting in line (dequeue)
   This action allows the user to serve the people next in line, which always happens to the person at the front of the queue. After this action is executed, it outputs the name of the person in the front of the queue, and then the "front" indicator will point to the person after the person that has been served. This "front" indicator indicates the person that will get served next in line.

   <img width="448" height="256" alt="image" src="https://github.com/user-attachments/assets/d4cb9263-8739-461c-90a3-fe9b4c241fbc" />

This is an example of an user serving 1 name on the queue.

3. See who is next in the line to be served (Peek)
   This action allows the user to check who is at the very front of the queue to be served next. How this works is that it checks who's name has the "front" indicator and outputs that name.

   <img width="468" height="270" alt="image" src="https://github.com/user-attachments/assets/63e75ab2-2f94-48c2-bc15-b13e25cf4607" />

This is an example continuing from the last 2 images. The person next in line is James because Maulana has already been served and is now out from the queue, so James is now is in the front of the queue.

4. Show the entire queue list
   This action allows the user to check the entire list of people who are inside the queue currently. This list will always output in the correct order, which is from the very front to the very end of the queue.

    <img width="411" height="167" alt="image" src="https://github.com/user-attachments/assets/06a3ebc2-42f6-4e70-b9ea-d837887d7ff5" />

This is an example of the queue list. The person that is in the front of the queue has the "FRONT" indicator on them, and so does the last person in the queue that has the "REAR" indicator.

5. Close the counter
   This action allows the user to close the program when done using the program. It works similar to the one on the stack program.

   <img width="959" height="278" alt="image" src="https://github.com/user-attachments/assets/e889d968-a6de-42f7-8d46-288cfefe9dc1" />

# C. Deque Undo Redo (deque.c)
