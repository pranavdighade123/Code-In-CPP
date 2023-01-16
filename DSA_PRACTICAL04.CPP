/*
DSA-PRACTICAL-04

Name:	 Pranav Dighade
Roll No: D48
Subject: DSA

AIM:Queues are frequently used in computer programming, and a typical example is the creation of a
job queue by an operating system. If the operating system does not use priorities, then the jobs
are processed in the order they enter the system. Write C++ program for simulating job queue.
Write functions to add job and delete job from queue.

*/


#include <iostream>
#include <queue>

std::queue<int> job_queue;

void add_job(int job_id) {
    job_queue.push(job_id);
}

void delete_job() {
    if (!job_queue.empty()) {
        job_queue.pop();
    } else {
        std::cout << "Error: Job queue is empty." << std::endl;
    }
}

int main() {
    add_job(1);
    add_job(2);
    add_job(3);
    std::cout << "Number of jobs in queue: " << job_queue.size() << std::endl;
    delete_job();
    std::cout << "Number of jobs in queue: " << job_queue.size() << std::endl;
    return 0;
}
