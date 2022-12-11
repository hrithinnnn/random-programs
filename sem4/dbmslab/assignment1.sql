drop table order2;
drop table order1;
drop table part;
drop table customer;
drop table employees;
create table EMPLOYEES(
emp_id varchar(4) constraint id_con check(emp_id like 'E%') constraint id_pk primary key,
emp_name varchar2(20),
dob date,
pin_code varchar(6),
city varchar(20)
);
rem create table


desc employees;
rem describe table


insert into employees values('E001', 'john doe', '19-Sep-2002','600017','chennai');
insert into employees values('E002', 'will smith', '19-Aug-2002','600017','chennai');
insert into employees values('F001', 'john doe', '19-Sep-2002','600017','chennai');
rem check constraint violation


insert into employees values('E001', 'john doe', '19-Sep-2002','600017','chennai');
insert into employees values('', 'john doe', '19-Sep-2002','600017','chennai');
rem primarykey violation


select * from employees;

create table CUSTOMER(
cust_no varchar2(4) constraint cust_no_pk primary key constraint cust_no_ch check(cust_no like 'C%'),
cust_name varchar2(20),
street_name varchar2(20),
pincode varchar2(6),
city varchar2(20),
dob date,
ph_no numeric(10) constraint ph_no_un unique
);
rem create table


desc customer;
rem describe table


insert into customer values('C001', 'vijay', 'tanjore road', '600017','chennai','10-Oct-2000','1234567890');
insert into customer values('D001', 'vijay', 'tanjore road', '600017','chennai','10-Oct-2000','1234567890');
rem check constraint violation


insert into customer values('', 'vijay', 'tanjore road', '600017','chennai','10-Oct-2000','1234567890');
insert into customer values('C002', 'vijay', 'tanjore road', '600017','chennai','10-Oct-2000','1234567890');
insert into customer values('C002', 'arjun', 'west mambalam', '600017','chennai','07-Apr-2002','0987654321');
rem primarykey violation


select * from customer;


create table PART(
part_no varchar2(4) constraint part_no_ch check(part_no like 'P%') constraint part_no_pk primary key,
part_name varchar2(10),
price numeric(10) constraint price_nn not null,
qty numeric(5) constraint qty_ch check(qty > 0)
);
rem create table



desc part;
rem describe table



insert into part values ('P001', 'tyre','5000','4');
insert into part values('P002', 'wheel','6000','4');
insert into part values('P001', 'tyre','5000','4');
rem primarykey violation


insert into part values('P001', 'tyre','','4');
rem unique value violation


insert into part values('X001', 'tyre','5000','4');
rem check constraint violation


select * from part;

create table ORDER1(
ord_no varchar2(4) constraint ord_no_pk primary key constraint ord_no_ch check(ord_no like 'O%'),
emp_id varchar2(4) constraint emp_id_fk references EMPLOYEES(emp_id),
cus_no varchar2(4) constraint cust_no_fk references CUSTOMER(cust_no),
ship_date date,
recd_date date,
constraint recd_date_ch check(recd_date>ship_date)
);
rem create table


desc order1;
rem describe table



insert into order1 values('O001','E001','C001','19-Sep-2022','20-Sep-2022');
rem insert into order1 values('O002','E002','C002','19-Sep-2022','20-Sep-2022');
insert into order1 values('','E001','C001','19-Sep-2022','20-Sep-2022');
insert into order1 values('O001','E450','C002','19-Sep-2022','20-Sep-2022');
rem primarykey violation


insert into order1 values('O001','E002','C005','30-Sep-2022','20-Sep-2022');
rem foreign key violation


insert into order1 values('O002','E001','C001','19-Sep-2022','20-Sep-2022');


rem check date constraint violation
select* from order1;



create table ORDER2(
order_no varchar2(4) constraint order_no_fk references order1(ord_no),
part_no varchar2(4) constraint part_no_fk references PART(part_no),
ord_qty numeric(5) constraint ord_qty_ch check(ord_qty>0),
constraint order2_comp_key primary key(order_no, part_no)
);

rem create table


rem describe table
desc order2;

insert into order2 values('O001','P001','20');
insert into order2 values('O002','P002','40');
insert into order2 values('','P005','20');
rem primary key violation


insert into order2 values('O003','','20');
rem primary key violation  


select * from order2;


rem add reorder level to parts and hire date to employees
alter table part add reorder_level numeric(2);
alter table employees add hire_date date;


desc part;
desc employees;


rem increase customer name size
alter table customer modify cust_name VARCHAR2(30);
desc customer;

rem drop dob column
alter table customer drop column dob;
desc customer;

rem make recieved date not null
alter table order1 modify recd_date date constraint recd_date_nn NOT NULL;

Rem q11
delete from order1 where ord_no='O001';
rem we cannot delete order because integrity constraint is violated

rem altering table to remove reference constraint
ALTER TABLE order2 DROP CONSTRAINT order_no_fk;


REM adding foreign keyt constraint
ALTER TABLE order2 ADD CONSTRAINT ord_no_fk FOREIGN KEY(order_no) REFERENCES order1(ord_no) ON DELETE CASCADE;


REM deleting aan order
delete from order1 where ord_no='O001';


REM displaying order1 table
SELECT * FROM order1;