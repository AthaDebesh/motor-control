Implement a C/C++ temperature monitoring and motor control system running on a Linux-based machine. The system shall monitor temperature values in real-time and execute predefined motor actions based on specific temperature thresholds with minimum timing jitters. 

System Requirements 

1. Temperature Monitoring & Sampling 

    Temperature data is provided as a time-series input. 

    The temperature shall be sampled every 100ms to ensure accurate readings. 

2. Motor Control Logic 

    The motor action is triggered every 100ms based on the latest sampled temperature value.  

    The system operates as follows:  

    Temperature < 85°C: Motor rotates to the right 

    85°C ≤ Temperature < 105°C: Motor rotates to the left 

    Temperature ≥ 105°C: Motor stops immediately 

3. Hardware Compatibility 

    The software must support different motor and sensor revisions (e.g., REV-0, REV-1, …) in a modular structure. Each hardware unit should have a unique identifier (e.g., ABC123 as a placeholder) 

4. Testing Strategy 

  To ensure system correctness and robustness a structured testing approach must be implemented. 
