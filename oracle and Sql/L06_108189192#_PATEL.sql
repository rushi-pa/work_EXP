-- ***********************
-- Name: Rushi Patel
-- ID: 108189192
-- Date: 7/17/2020
-- Purpose: Lab 6 DBS311
-- ***********************

-- Question 1 – The company wants to calculate the employees’ annual salary:
-- Q1 SOLUTION –


set serveroutput on
create or replace procedure calcualte_salary as hire_up number;
empID number;
fname varchar2(255 byte);
lname varchar2(255 BYTE);
hire_year number;
current_year number;
current_month number;
temp number;
BEGIN
DECLARE 
SALARY EMPLOYEES.employee_id%TYPE := 10000;
BEGIN
empID := &empID;
select extract(month from hire_date),extract(year from hire_date)
into hire_up,hire_year from employees
where employee_id = empID;
select first_name,last_name
into fname,lname from employees where employee_id = empID;
select extract (month from SYSDATE) into current_month from DUAL;
select extract (year from SYSDATE)into current_year from DUAL;
if hire_up < current_month then
FOR i IN 1..5 LOOP
SALARY := SALARY *1.05;
end loop;
dbms_output.put_line('First name: ' || fname);
dbms_output.put_line('Last name: ' || lname);
dbms_output.put_line('Salary: ' || TRUNC(SALARY));

elsif hire_up > current_month then
FOR i IN 1..4 LOOP
SALARY := SALARY *1.05;
end LOOP;
dbms_output.put_line('First name: ' || fname);
dbms_output.put_line('Last name: ' || lname);
dbms_output.put_line('Salary: ' || TRUNC(SALARY));
end if;
end;
exception
WHEN NO_DATA_FOUND
  THEN 
      DBMS_OUTPUT.PUT_LINE ('No Data Found!');
when others
then 
dbms_output.put_line('Error!');

end;

/
begin 
calcualte_salary();
end;

-- Question 2 –  Write a stored procedure named warehouses_report to print the warehouse ID, warehouse name, and the city where the warehouse is located. Use the following sample format for all warehouses:
-- Q2 SOLUTION –
create or replace procedure warehouses_report as 
BEGIN
declare 
CURSOR emp_cursor IS
SELECT warehouse_id,warehouse_name,CITY, state
FROM LOCATIONS join warehouses
using(location_id);
begin
FOR item IN emp_cursor
LOOP
	DBMS_OUTPUT.PUT_LINE ('Warehouse Id: ' || item.warehouse_id );
    DBMS_OUTPUT.PUT_LINE('Warehouse name: ' || item.warehouse_name);
    DBMS_OUTPUT.PUT_LINE('City: ' || item.city);
    if item.state is null then
    DBMS_OUTPUT.PUT_LINE('State : Unkown state');
    elsif item.state is not null then
    DBMS_OUTPUT.PUT_LINE('State: ' || item.state);
    end if;
END LOOP;
IF emp_cursor%ISOPEN THEN
CLOSE emp_cursor;
END IF;
end;
end;
/
begin
warehouses_report();
end;



-- Question 3 – Redo the procedure to show output of 1 line per warehouse.
-- Q3 SOLUTION –
create or replace procedure warehouses_report as 
BEGIN
declare 
CURSOR emp_cursor IS
SELECT warehouse_id,warehouse_name,CITY, state
FROM LOCATIONS join warehouses
using(location_id);
begin
FOR item IN emp_cursor
LOOP
	DBMS_OUTPUT.PUT_LINE ('Warehouse Id: ' || item.warehouse_id || ' ,Warehouse name: ' || item.warehouse_name ||',City: ' || item.city);
    if item.state is null then
    DBMS_OUTPUT.PUT_LINE('State : Unkown state');
    elsif item.state is not null then
    DBMS_OUTPUT.PUT_LINE('State: ' || item.state);
    end if;
END LOOP;
IF emp_cursor%ISOPEN THEN
CLOSE emp_cursor;
END IF;
end;
end;
/
begin
warehouses_report();
end;
