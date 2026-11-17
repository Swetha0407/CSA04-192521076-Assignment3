# CSA04-192521076-Assignment3# Operating Systems – Assignment 3 (CO3)
## Memory Management, Virtual Memory, Page Replacement and Disk Management

**Course Code:** CSA04  
**Subject:** Operating Systems  
**Assignment:** Assignment 3 – CO3  
**Student:** Swetha S  
**Register Number:** 192521076

---

## 1. Project Overview

This repository contains the implementation and analysis of Assignment 3 for the Operating Systems course. The assignment explores fundamental operating-system concepts related to memory management, address translation, virtual memory, page replacement, linking, loading and disk management.

The work combines theoretical explanations, C programming, Python simulations, Linux system-level experiments, mathematical calculations and practical design decisions.

The objective is to understand how operating systems manage memory and storage resources, evaluate different approaches through implementation, and justify suitable mechanisms for real-world computing environments.

## 2. Assignment Objectives

The major objectives are:

- Understand static linking, dynamic linking and runtime loading.
- Implement paging and logical-to-physical address translation.
- Study segmentation, memory protection and address validation.
- Analyse demand paging, page faults, working sets and copy-on-write.
- Compare FIFO, LRU, Optimal and Clock page-replacement algorithms.
- Evaluate disk organisation, RAID configurations and storage reliability.
- Design a memory-management strategy for a resource-constrained smart-factory edge device.

## 3. Repository Structure

The repository is organised into seven task directories.

```text
CSA04-192521076-Assignment3/
│
├── Task01/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
├── Task02/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
├── Task03/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
├── Task04/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
├── Task05/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
├── Task06/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
├── Task07/
│   ├── Source files
│   ├── Execution scripts
│   ├── outputs/
│   └── Evidence/
│
└── run_all.sh
```

Each task is maintained independently so that its implementation and results can be examined without depending on the other tasks.

## 4. Technologies and Tools

| Technology | Purpose |
|---|---|
| C | System-level programming and OS demonstrations |
| Python 3 | Simulations, calculations and analysis |
| GCC | Compiling C programs |
| Linux / Ubuntu | Execution environment |
| WSL2 | Running Ubuntu on Windows |
| Bash | Automating compilation and execution |
| Git and GitHub | Version control and project hosting |

### Execution Environment

The implementations were developed and tested using Ubuntu under Windows Subsystem for Linux (WSL2).

The experiments involving process memory, page faults, system calls and timing measurements are environment-dependent. Results may vary across operating systems, hardware configurations and kernel versions.

## 5. Task-wise Implementation

### Task 1 – Linking, Loading and Address Binding

**Concepts:** Static linking, dynamic linking, explicit runtime loading and address binding.

This task investigates how executable programs use external libraries.

The implementation compares statically linked and dynamically linked versions of a banking application using an encryption library.

It also demonstrates:

- Executable size comparison.
- Runtime library dependencies using `ldd`.
- Memory mappings through `/proc/self/maps`.
- Runtime library loading using `dlopen()`.
- Symbol resolution using `dlsym()`.
- Library replacement and missing-library error handling.

**Key observation:** Static linking produces a larger executable, whereas dynamic linking reduces executable size and allows shared libraries to be updated independently.

### Task 2 – Paging and Address Translation

**Concepts:** Pages, frames, page tables, logical addresses, physical addresses, internal fragmentation and TLB.

This task implements a paging-based address translator.

A logical address is divided into a page number and an offset. The page table is used to identify the corresponding physical frame, and the physical address is calculated using the frame number and offset.

The task also investigates:

- Page-table size for different virtual address widths.
- Internal fragmentation for different page sizes.
- Effective access time with varying TLB hit ratios.
- Multi-level, hashed and inverted page tables.

**Key observation:** Paging allows non-contiguous physical-memory allocation and eliminates external fragmentation, although internal fragmentation and page-table overhead remain.

### Task 3 – Segmentation

**Concepts:** Segment tables, base addresses, limits, memory protection and segmentation faults.

This task demonstrates memory organisation using logical segments such as code, data and stack.

The implementation validates logical addresses against segment limits and calculates physical addresses using the segment base.

It also examines:

- Valid and invalid segment references.
- Segment-boundary protection.
- Process memory mappings.
- Invalid memory access and segmentation faults.
- Comparison of paging, segmentation and segmented paging.

**Key observation:** Segmentation provides logical memory organisation and protection, while paging offers more flexible physical-memory allocation.

### Task 4 – Virtual Memory and Demand Paging

**Concepts:** Demand paging, page faults, working sets, thrashing and copy-on-write.

This task examines how an operating system manages virtual memory when the complete application address space cannot remain resident in physical memory.

The experiments cover:

- Sequential and random memory access.
- First-touch page faults.
- Copy-on-write behaviour following `fork()`.
- Effective access time under different page-fault rates.
- Working-set management.
- Memory allocation and thrashing.

**Key observation:** Demand paging improves memory utilisation, but excessive page faults can significantly reduce system performance. Applications should maintain an efficient working set.

### Task 5 – Page-Replacement Algorithms

**Concepts:** FIFO, LRU, Optimal and Clock page replacement.

This task implements and compares four page-replacement algorithms.

| Algorithm | Replacement strategy |
|---|---|
| FIFO | Replaces the page loaded earliest |
| LRU | Replaces the least recently used page |
| Optimal | Replaces the page whose next use is farthest in the future |
| Clock | Uses a reference bit and circular pointer to provide a second chance |

The simulations evaluate:

- Page-fault counts for different frame allocations.
- Behaviour under locality-heavy workloads.
- Behaviour under random workloads.
- Belady's anomaly.
- Execution-time differences between algorithms.

**Key observation:** LRU performs well when workloads exhibit temporal locality. Clock provides a practical approximation with lower bookkeeping overhead, while Optimal serves as a theoretical benchmark.

### Task 6 – Disk Management and RAID

**Concepts:** Disk formatting, partitioning, boot process, bad-block management, RAID and swap space.

This task studies the organisation and reliability of secondary storage.

The analysis includes:

- Low-level formatting and logical formatting.
- Disk partitioning.
- Boot-block and bootloader operations.
- Bad-block handling.
- Linux disk inspection.
- RAID capacity calculations.
- RAID 0, RAID 1, RAID 5, RAID 6 and RAID 10.
- Swap partitions and swap files.

**Key observation:** RAID configurations provide different trade-offs between usable capacity, redundancy and performance. RAID must be complemented by independent backups and recovery procedures.

### Task 7 – Memory Management for a Smart-Factory Edge Device

**Concepts:** Real-time memory allocation, paging, memory locking, demand paging and deterministic execution.

The final task develops a memory-management plan for a smart-factory edge device with 2 GiB of RAM and no swap space.

The design considers three major workloads:

1. Real-time control task.
2. Machine-learning task.
3. Logging task.

The proposed memory allocation is:

| Component | Allocation |
|---|---:|
| Real-time control | 128 MiB |
| Machine learning | 1,536 MiB |
| Logging | 128 MiB |
| OS and drivers | 256 MiB |
| **Total** | **2,048 MiB** |

The implementation evaluates memory locking using `mlockall()` and compares observed execution latency.

**Key observation:** Memory locking prevents selected pages from being paged out, but it does not independently guarantee hard real-time behaviour. A real-time kernel or RTOS, preallocated memory and careful scheduling are required for stronger timing guarantees.

## 6. Running the Project

### Prerequisites

Install the following in an Ubuntu environment:

- GCC compiler
- Python 3
- Bash
- Standard Linux development utilities

Update the package list:

```bash
sudo apt update
```

Install the required tools:

```bash
sudo apt install build-essential python3 python3-pip
```

### Execute an Individual Task

Navigate to the required task directory:

```bash
cd Task01
```

Run its execution script:

```bash
bash run.sh
```

Repeat the same process for other task directories.

### Execute All Tasks

From the repository root:

```bash
chmod +x run_all.sh
./run_all.sh
```

The script executes the task-specific run scripts sequentially. Individual task outputs are maintained in their respective `outputs/` directories.

## 7. Evidence and Results

Each task contains an `Evidence/` directory with relevant execution captures and visual results.

The `outputs/` directories preserve the program outputs and experimental data used for analysis.

The evidence covers:

- Linking and runtime library loading.
- Paging address translation.
- Segmentation and memory protection.
- Memory access and copy-on-write.
- Page-replacement algorithm results.
- RAID capacity calculations.
- Memory-locking experiments.

The page-replacement experiment also includes a comparison chart showing the behaviour of the algorithms under a locality-heavy workload.

## 8. Important Findings

The assignment demonstrates several important operating-system principles:

1. Dynamic linking reduces executable size and supports independent library updates.
2. Paging enables flexible physical-memory allocation but introduces page-table and internal-fragmentation overhead.
3. Segmentation provides logical protection boundaries for different memory regions.
4. Demand paging improves memory utilisation, but frequent page faults can cause severe performance degradation.
5. LRU and Clock are practical replacement approaches for workloads with locality.
6. RAID selection requires balancing capacity, redundancy and performance.
7. Real-time workloads require predictable memory allocation and careful control of page faults and scheduling.

## 9. Limitations

- Performance measurements depend on the execution environment and should not be treated as universal benchmarks.
- The Optimal page-replacement algorithm requires future reference knowledge and is used as a comparison baseline rather than a practical online policy.
- The memory-locking experiment does not establish hard real-time guarantees.
- RAID reliability calculations use simplified disk-failure assumptions and do not account for all correlated failures or operational risks.
- The smart-factory memory plan is a design proposal evaluated through the assignment experiments, not a deployed industrial control system.

## 10. Conclusion

Assignment 3 provides practical exposure to memory management, virtual-memory mechanisms, page replacement, linking and loading, and disk organisation.

By combining implementations, simulations and theoretical analysis, the project demonstrates how operating systems make resource-management decisions under different workload requirements.

The final smart-factory design highlights the importance of bounded memory allocation, predictable execution, efficient workload management and appropriate operating-system mechanisms for real-time and non-real-time tasks.

---

**Course:** CSA04 – Operating Systems  
**Assignment:** Assignment 3 – CO3  
**Student Register Number:** 192521076