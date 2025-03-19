Below is a **two-part problem** specification. In the first part, you must write a function to **read meeting times** from a file. In the second part, you must write a function to **calculate the minimum number of rooms** required and **assign meetings** to those rooms.

---

## **Problem 1: Read Meetings from File**

### **Function Signature**

```python
def read_meetings_from_file(filename):
    """
    Reads meeting information from the specified file and returns
    a list of tuples (start_time, end_time).
    """
```

### **Description**

You have a text file, each line containing two strings representing a start time and an end time (e.g., `"HH:MM HH:MM"`). Your goal is to read these lines from the file, parse them, and return a list of 2-tuples. For instance, a file might look like this:

```
01:00 02:30
09:15 10:00
10:00 11:30
10:30 11:00
```

### **Requirements**

1. **Read** each line from the file `filename`.
2. **Split** the line by whitespace to separate the start time and end time.
3. **Strip** any trailing newline characters from each time field.
4. **Return** a list of tuples, where each tuple is `(start_time, end_time)`.

### **Example**

- If the file content is:

  ```
  01:00 02:30
  09:15 10:00
  10:00 11:30
  10:30 11:00
  ```

  Then the function should return:

  ```python
  [
      ("01:00", "02:30"),
      ("09:15", "10:00"),
      ("10:00", "11:30"),
      ("10:30", "11:00")
  ]
  ```

---

## **Problem 2: Minimum Meeting Rooms**

### **Function Signature**

```python
def min_meeting_rooms(meetings):
    """
    Given a list of (start_time, end_time) tuples, return a tuple of the form:
    (number_of_rooms, [ [ (start, end), ... ], [ (start, end), ... ], ... ])
    """
```

### **Description**

Given a list of meetings (start and end times), determine:

1. The **minimum number of rooms** needed so that no two meetings overlap in the same room.
2. A **room assignment** for all meetings, showing exactly which meetings go to which room.

You can assume:
- A meeting that ends exactly at the same time another begins does **not** cause an overlap.  
  For example, one meeting ending at `10:00` and another starting at `10:00` may use the same room.

### **Output Format**

The function should return a tuple:

```
(
    min_room_count,
    [
        [ (start1, end1), (start2, end2), ... ],   # Meetings in Room 1
        [ (start3, end3), (start4, end4), ... ],   # Meetings in Room 2
        ...
    ]
)
```

**Example**:  
Suppose the `meetings` list is:

```python
[
    ("01:00", "02:30"),
    ("09:15", "10:00"),
    ("10:00", "11:30"),
    ("10:30", "11:00")
]
```

A valid result might be:

```python
(2, [
    [("01:00", "02:30"), ("10:00", "11:30")],
    [("09:15", "10:00"), ("10:30", "11:00")]
])
```

This shows that:
- **2 rooms** are required.
- The first room holds meetings `(01:00–02:30)` and `(10:00–11:30)`.
- The second room holds `(09:15–10:00)` and `(10:30–11:00)`.

### **Hint**

A common approach involves using a **min-heap (priority queue)** to keep track of meeting end times. When a new meeting starts, compare its start time to the earliest finishing meeting in the heap. This strategy is often used to achieve efficient scheduling and can help determine whether you can reuse a room or need a new one.

---

**End of Problems**
