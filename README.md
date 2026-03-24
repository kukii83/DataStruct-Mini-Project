# DataStruct-Mini-Project

Nama: Maulana Anugra Putra

NRP: 5025251159

# A. Stack Browser History
This C program simulates a browser history system using a stack data structure, which follows the Last In, First Out (LIFO) principle. Each time a user visits a new webpage, the URL is pushed onto the stack, making it the current page at the top. When the user presses the back button, the program pops the top element, effectively removing the most recently visited page and returning to the previous one. The program also allows users to view the current page using a peek operation and display the full browsing history from most recent to oldest.

This is how the program looks like:

<img width="1242" height="299" alt="Screenshot 2026-03-24 224627" src="https://github.com/user-attachments/assets/4bdb06e5-9614-4763-b147-862eea91f42e" />

When run, it outputs a browser menu like shown in the image. Here, the user can choose between 5 actions. After an action is done, it will go back to this starting menu. This will loop until the user decides to exit the program (which is action no. 0) which will break the loop and end the program. Here's the list that the user can do:

1. Visiting a webpage
   This action allows the user to visit a webpage. This is the PUSH function for the stack concept.

   <img width="372" height="268" alt="Screenshot 2026-03-24 225126" src="https://github.com/user-attachments/assets/d71ad3fc-a253-43b2-8173-1c2575faf364" />

When option 1 is chosen, it will tell the user to input the webpage like shown in the image. It will then shows that it have visited the webpage after the user types in the webpage.

<img width="392" height="293" alt="Screenshot 2026-03-24 225140" src="https://github.com/user-attachments/assets/cf4a168e-4abc-4ccd-853d-894a5c604bdf" />

Then, after this is done, it will return to the main browser menu, asking for the next input from the user.
