Certainly! Below is a `README.md` file containing advanced SQL queries with explanations and examples. Each example is illustrated using sample tables.

---

# Advanced SQL Queries

This `README.md` file contains examples of advanced SQL queries. Each example is accompanied by sample tables and detailed explanations.

## Sample Tables

### `employees` Table

| id  | name  | department_id | hire_date  | salary | manager_id |
| --- | ----- | ------------- | ---------- | ------ | ---------- |
| 1   | Alice | 1             | 2022-01-15 | 60000  | NULL       |
| 2   | Bob   | 2             | 2021-06-23 | 70000  | 1          |
| 3   | Carol | 1             | 2023-03-10 | 65000  | 1          |
| 4   | Dave  | 3             | 2020-11-30 | 50000  | 2          |
| 5   | Eve   | 2             | 2024-02-01 | 72000  | 2          |

### `departments` Table

| id  | department_name |
| --- | --------------- |
| 1   | Sales           |
| 2   | Engineering     |
| 3   | HR              |

### `projects` Table

| id  | project_name | department_id | start_date | end_date   |
| --- | ------------ | ------------- | ---------- | ---------- |
| 1   | Alpha        | 1             | 2023-01-01 | 2023-12-31 |
| 2   | Beta         | 2             | 2023-02-01 | 2023-11-30 |
| 3   | Gamma        | 2             | 2023-03-01 | 2024-01-31 |
| 4   | Delta        | 3             | 2023-04-01 | 2023-10-31 |

## Advanced SQL Queries

### 1. **Find the Highest Salary in Each Department**

**Query:**

```sql
SELECT department_id, MAX(salary) AS highest_salary
FROM employees
GROUP BY department_id;
```

**Explanation:**

- Groups employees by `department_id` and finds the highest salary within each department.

### 2. **Find Employees with the Most Recent Hire Dates**

**Query:**

```sql
SELECT name, hire_date
FROM employees
WHERE hire_date = (SELECT MAX(hire_date) FROM employees);
```

**Explanation:**

- Retrieves employees who were hired on the most recent date.

### 3. **Calculate the Total Number of Projects by Department**

**Query:**

```sql
SELECT d.department_name, COUNT(p.id) AS total_projects
FROM projects p
JOIN departments d ON p.department_id = d.id
GROUP BY d.department_name;
```

**Explanation:**

- Counts the number of projects per department and groups by `department_name`.

### 4. **Find the Average Salary of Employees Reporting to Each Manager**

**Query:**

```sql
SELECT e.manager_id, AVG(e.salary) AS avg_salary
FROM employees e
WHERE e.manager_id IS NOT NULL
GROUP BY e.manager_id;
```

**Explanation:**

- Computes the average salary of employees under each manager.

### 5. **List Departments with No Active Projects**

**Query:**

```sql
SELECT d.department_name
FROM departments d
LEFT JOIN projects p ON d.id = p.department_id AND p.end_date > CURRENT_DATE
WHERE p.id IS NULL;
```

**Explanation:**

- Lists departments that do not have any active projects.

### 6. **Find Employees Not Assigned to Any Projects**

**Query:**

```sql
SELECT e.name
FROM employees e
LEFT JOIN projects p ON e.department_id = p.department_id
WHERE p.id IS NULL;
```

**Explanation:**

- Retrieves employees who are not associated with any project.

### 7. **Get the Top 3 Highest Paid Employees in Each Department**

**Query:**

```sql
WITH RankedSalaries AS (
    SELECT name, department_id, salary,
           ROW_NUMBER() OVER (PARTITION BY department_id ORDER BY salary DESC) AS rank
    FROM employees
)
SELECT name, department_id, salary
FROM RankedSalaries
WHERE rank <= 3;
```

**Explanation:**

- Uses a Common Table Expression (CTE) to rank salaries within each department and selects the top 3.

### 8. **Identify Employees Who Have Worked on Multiple Projects**

**Query:**

```sql
SELECT e.name, COUNT(p.id) AS project_count
FROM employees e
JOIN projects p ON e.department_id = p.department_id
GROUP BY e.name
HAVING COUNT(p.id) > 1;
```

**Explanation:**

- Finds employees involved in more than one project.

### 9. **Get the Departments with the Longest Running Projects**

**Query:**

```sql
SELECT d.department_name, MAX(DATEDIFF(p.end_date, p.start_date)) AS longest_project_duration
FROM projects p
JOIN departments d ON p.department_id = d.id
GROUP BY d.department_name;
```

**Explanation:**

- Calculates the duration of projects and retrieves the longest duration for each department.

### 10. **Find Employees with No Direct Reports**

**Query:**

```sql
SELECT e.name
FROM employees e
LEFT JOIN employees m ON e.id = m.manager_id
WHERE m.id IS NULL AND e.manager_id IS NOT NULL;
```

**Explanation:**

- Lists employees who do not have any direct reports.

### 11. **Calculate the Total Salary Expenditure per Department**

**Query:**

```sql
SELECT d.department_name, SUM(e.salary) AS total_salary_expenditure
FROM employees e
JOIN departments d ON e.department_id = d.id
GROUP BY d.department_name;
```

**Explanation:**

- Computes the total salary expenditure for each department.

### 12. **Find the Department with the Highest Average Salary**

**Query:**

```sql
SELECT d.department_name, AVG(e.salary) AS avg_salary
FROM employees e
JOIN departments d ON e.department_id = d.id
GROUP BY d.department_name
ORDER BY avg_salary DESC
LIMIT 1;
```

**Explanation:**

- Retrieves the department with the highest average salary.

### 13. **Identify Employees Who Were Hired in the Last 30 Days**

**Query:**

```sql
SELECT name, hire_date
FROM employees
WHERE hire_date >= CURRENT_DATE - INTERVAL '30' DAY;
```

**Explanation:**

- Lists employees who were hired in the last 30 days.

### 14. **Find Projects with No Assigned Employees**

**Query:**

```sql
SELECT p.project_name
FROM projects p
LEFT JOIN employees e ON p.department_id = e.department_id
WHERE e.id IS NULL;
```

**Explanation:**

- Lists projects that do not have any assigned employees.

### 15. **Find Employees Who Have Never Managed a Project**

**Query:**

```sql
SELECT e.name
FROM employees e
LEFT JOIN projects p ON e.id = p.manager_id
WHERE p.id IS NULL;
```

**Explanation:**

- Identifies employees who have not managed any project.

### 16. **Get the Average Project Duration by Department**

**Query:**

```sql
SELECT d.department_name, AVG(DATEDIFF(p.end_date, p.start_date)) AS avg_project_duration
FROM projects p
JOIN departments d ON p.department_id = d.id
GROUP BY d.department_name;
```

**Explanation:**

- Computes the average duration of projects for each department.

### 17. **List All Managers and Their Subordinates**

**Query:**

```sql
SELECT m.name AS manager_name, e.name AS subordinate_name
FROM employees e
JOIN employees m ON e.manager_id = m.id;
```

**Explanation:**

- Lists each manager along with their direct subordinates.

### 18. **Find Departments with More Than 3 Employees**

**Query:**

```sql
SELECT d.department_name, COUNT(e.id) AS employee_count
FROM employees e
JOIN departments d ON e.department_id = d.id
GROUP BY d.department_name
HAVING COUNT(e.id) > 3;
```

**Explanation:**

- Retrieves departments that have more than three employees.

### 19. **Find Employees Whose Salary is Above the Median Salary**

**Query:**

```sql
WITH SalaryList AS (
    SELECT salary, ROW_NUMBER() OVER (ORDER BY salary) AS row_num, COUNT(*) OVER () AS total_rows
    FROM employees
)
SELECT name, salary
FROM employees e
JOIN SalaryList s ON e.salary = s.salary
WHERE s.row_num > total_rows / 2;
```

**Explanation:**

- Uses a CTE to find the median salary and selects employees earning more than the median.

### 20. **Find the Most Recently Ended Project for Each Department**

**Query:**

```sql
WITH LatestProjects AS (
    SELECT department_id, project_name, end_date,
           ROW_NUMBER() OVER (PARTITION BY department_id ORDER BY end_date DESC) AS rn
    FROM projects
)
SELECT department_id, project_name, end_date
FROM LatestProjects
WHERE rn = 1;
```

**Explanation:**

- Uses a CTE to rank projects by end date within each department and selects the most recently ended project.

---

This `README.md` file provides advanced SQL queries with explanations and example results. Adjust the queries based on your database schema and specific requirements.
