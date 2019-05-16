# Instilling Excitement and Caution About Parallelism
Introducing the Benefits and Pitfalls of Parallelism in Introductory Programming Courses
## OVERVIEW
We are integrating the concepts of concurrency and parallelism into our introductory programming sequence at Ithaca College. 

Our current work encourages students to confront and continually revisit two main questions as their skills mature:
1. Why are concurrent/parallel programming approaches useful? 
2. What are the common pitfalls when applying concurrent/parallel processing?

We consider this thematic approach to be important because the added lessons will be spread throughout three semesters and so students need a common thread to ensure a simple, coherent lesson.
Currently we have piloted changes to three courses and have conducted informal evaluation through discussion and observation with both students and instructors. Materials are being refined and more formal evaluation metrics are being applied to measure whether the repeated exposure (even when limited in scope) yields a useful basis of understanding upon which higher-level courses can build. All materials are available online for consideration or use.
## IMPLEMENTATION
### CS I: Python
We introduced two different lessons in our introductory python course that use the high-level thread pools functionality from the multiprocessing library in python3: one that speeds web-scraping activities, and another that speeds image processing tasks.
Excitement: Parallelism can be used to increase the efficiency of our code. The setup of these exercises is fairly simple and therefore students can see the benefits of parallelism easily. Both subjects (web scraping and image manipulation) were already included in the course material, which gives the students grounded examples of where parallelism can be useful. 
Caution: Be careful how you parallelize with shared memory. When parallelizing the image manipulation code, you can parallelize the work within an image, or you can parallelize different image manipulations (e.g., black/white filter and rotation). Both will produce speed up, but the latter will produce a broken image. 
### CS II: Java
We introduced a multi-day lesson involving message-passing parallelism to make a simple chat program using lower-level java structures: threads and sockets. 
Excitement: Parallelism can be useful and necessary to coordinate tasks that span multiple processes. This lesson introduces our students to the idea that programs are not limited to a single computer, processor, or process. 
Caution: message-passing parallel processes must be thoughtfully coordinated. Students are introduced to the coordination that must occur between client and server that invites the use of server threads, and then the use of threads to improve a responsive interface (such that the client can read/write simultaneously). Timing issues of when client and server are started and stopped are also considered.
### Introduction to Data Structures: C++
We introduced parallel versions of linear search and merge sort, using OpenMP and threaded recursion respectively.
Excitement: While asymptotic analysis can show the limits of performance, parallelism can provide practical efficiency boosts in realistic settings. This course is primarily focused on efficiency, and therefore students gain a more nuanced and meaningful understanding of the same types of speed up demonstrated in CS I. 
Caution: Coordination between threads can be necessary and too many threads can be worse than one. We demonstrate these principles by showing how naïve parallel linear search can yield different answers (i.e., not the first occurrence of the value), and by applying too many threads to parallel merge sort.
## CHALLENGES TO IMPLEMENTATION
Implementation in these contexts all offered unique challenges that hampered their incorporation into the curriculum, including: 1) lack of significant speed-up by parallelizing CPU-intensive tasks in Python, likely related to the Global Interpreter Lock (GIL), 2) wide-ranging prerequisite knowledge needed to understand the context of the networked chat program in java, and 3) difficulty integrating OpenMP-capable compliers with the development environment used in the course.
