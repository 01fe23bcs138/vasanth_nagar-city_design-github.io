## Problem Definition

In the wake of frequent natural disasters such as floods, earthquakes, and fires, there is an urgent need for an intelligent disaster management system. The primary goal of this project is to design a **Smart Disaster Response and Evacuation System** that can ensure efficient rescue operations, optimal evacuation routes, real-time decision-making, and resource allocation during emergencies. By combining data-driven algorithms and automation, this system aims to minimize casualties, reduce response times, and optimize resource utilization.

This system will address the following **12 sub-problems**, along with the **algorithms applied** to solve them:

---

### Sub-Problems and Algorithms

1. **Evacuation Request Scheduling**  
   - **Objective**: Handle evacuation requests based on the severity of the threat in each zone.  
   - **Algorithm**: **Priority Queue** (to process evacuation requests based on urgency).

2. **Disaster Impact Mapping**  
   - **Objective**: Map affected zones and track the severity of disasters in real-time.  
   - **Algorithm**: **Hashing** (to store and retrieve zone-specific disaster impact data).

3. **Optimal Evacuation Routing**  
   - **Objective**: Find the safest and fastest evacuation routes to shelters.  
   - **Algorithm**: **Dijkstra's Algorithm** (to calculate the shortest and safest paths to shelters).

4. **Dynamic Resource Allocation**  
   - **Objective**: Efficiently allocate resources such as medical supplies and food to disaster-hit zones.  
   - **Algorithm**: **Bellman-Ford Algorithm** (to calculate shortest paths while considering dynamic changes in resource demands).

5. **Shelter-to-Zone Connectivity Analysis**  
   - **Objective**: Assess connectivity between shelters and disaster zones to optimize resource distribution.  
   - **Algorithm**: **Floyd-Warshall Algorithm** (to determine all-pairs shortest paths between zones and shelters).

6. **Evacuation Zone Network Design**  
   - **Objective**: Design a cost-effective network of evacuation zones and shelters.  
   - **Algorithm**: **Prim's Algorithm** (to construct a Minimum Spanning Tree for efficient evacuation zone connections).

7. **High-Risk Zone Prioritization**  
   - **Objective**: Rank disaster-affected zones based on risk levels for rescue operation prioritization.  
   - **Algorithm**: **Heap Sort** (to order zones by severity of disaster impact).

8. **Task Scheduling for Rescue Operations**  
   - **Objective**: Organize and prioritize rescue tasks based on urgency and deadlines.  
   - **Algorithm**: **Merge Sort** (to sort rescue tasks based on priority).

9. **Flood Path Prediction**  
   - **Objective**: Simulate and predict the spread of floods in low-lying areas for preemptive evacuation.  
   - **Algorithm**: **Breadth-First Search (BFS)** (to simulate water flow in the disaster network).

10. **Critical Infrastructure Identification**  
    - **Objective**: Identify infrastructure components (e.g., dams, bridges) whose failure could worsen the disaster’s impact.  
    - **Algorithm**: **Depth-First Search (DFS)** (to locate critical components of the infrastructure).

11. **Resource Distribution Cost Minimization**  
    - **Objective**: Minimize costs associated with distributing resources across disaster-hit zones.  
    - **Algorithm**: **Kruskal's Algorithm** (to design an efficient resource distribution network).

12. **Dynamic Evacuation Path Updates**  
    - **Objective**: Update evacuation paths dynamically to account for blocked roads or emerging hazards.  
    - **Algorithm**: **Linked Lists** (to efficiently manage changes in evacuation routes in real time).

---

## Objectives

- **Develop an intelligent disaster management system** that integrates real-time data to predict and respond to emergency scenarios.  
- **Leverage 12 key algorithms** to solve sub-problems related to evacuation, resource management, routing, and prioritization.  
- **Ensure modular functionality**, allowing users to interact with and test individual components for simulation and real-world application.

---

## Process

1. **Input**: Disaster-related data such as hazard levels, zone maps, resource availability, and shelter locations.  
2. **Implementation**: Use the 12 algorithms to address sub-problems, integrate their results, and build a comprehensive disaster management system.  
3. **Output**: A responsive, efficient, and user-friendly disaster response system that minimizes disaster impact and streamlines evacuation and rescue operations.

---

This project aims to create a practical, algorithm-driven solution for disaster management, addressing all key aspects from evacuation planning to resource distribution and infrastructure assessment. Let us know if you'd like to contribute or learn more!

## Individual Implementation

## Sahana R
1. **Dynamic Resource Allocation**
2. **High-Risk Zone Prioritization**
3. **Critical Infrastructure Identification**
   
## Rachana P Rane
1. **Disaster Impact Mapping**
2. **Optimal Evacuation Routing**
3. **Resource Distribution Cost Minimization**

## Nishita P Jahagirdar
1. **Evacuation Request Scheduling**
2. **Evacuation Zone Network Design**
3. **Dynamic Evacuation Path Updates**

## Tanushree Manjunath
1. **Shelter-to-Zone Connectivity Analysis**
2. **Flood Path Prediction**
3. **Task Scheduling for Rescue Operations** 
