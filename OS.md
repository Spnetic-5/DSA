# Commonly Asked Operating Systems Questions : 
ATB:)

### What is a process and process table? What are different states of process?
- A **process** is an instance of program in execution. For example a Web Browser is a process, a shell (or command prompt) is a process.
- The **operating system** is responsible for managing all the processes that are running on a computer and allocated each process a certain amount of time to use the processor. OS also allocates resources such as computer memory or disks to processes. 
- To keep track of the state of all the processes, the operating system maintains a table known as the **process table**. Inside this table, every process is listed along with the resources the processes is using and the current state of the process. 
- **States** - Processes can be in one of three states: **running**, **ready**, or **waiting**. The running state means that the process has all the resources it need for execution and it has been given permission by the operating system to use the processor. Only one process can be in the running state at any given time. The remaining processes are either in a waiting state (i.e., waiting for some external event to occur such as user input or a disk access) or a ready state (i.e., waiting for permission to use the processor). In a real operating system, the waiting and ready states are implemented as queues which hold the processes in these states. 
 
 ### What is a Thread? What are the differences between process and thread? 
 - A **thread** is a single sequence stream within in a process or entities scheduled for execution on the CPU. Because threads have some of the properties of processes, they are sometimes called **lightweight processes**.
 - Threads are popular way to improve application through **parallelism**. For example, in a browser, multiple tabs can be different threads. MS word uses multiple threads, one thread to format the text, other thread to process inputs, etc. 
 - A thread has its own program counter (PC), a register set, and a stack space. Threads are not independent of one other like processes as a result threads shares with other threads their code section, data section and OS resources like open files and signals. 

### What are the benefits of multithreaded programming? 
- It makes the system more responsive and enables resource sharing. It leads to the use of multiprocess architecture.It is more economical and preferred. 

### What are the different scheduling algorithms 
- First-Come, First-Served (FCFS) Scheduling. 
- Shortest-Job-Next (SJN) Scheduling. 
- Priority Scheduling. 
- Shortest Remaining Time. 
- Round Robin(RR) Scheduling. 
- Multiple-Level Queues Scheduling. 
