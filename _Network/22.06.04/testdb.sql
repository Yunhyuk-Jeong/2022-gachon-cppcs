create database testdb;

use testdb;

create table NewBook(
bookid integer,
bookname varchar(20),
publisher varchar(20),
price integer);

create table NewCustomer(
custid integer primary key,
name varchar(40),
address varchar(40),
phone varchar(30));

create table NewOrders(
orderid integer,
custid integer not null,
bookid integer not null,
saleprice integer,
orderdate DATE, primary key(orderid),
foreign key(custid) references
newcustomer(custid) on delete cascade);

create table member(
memberid varchar(20) not null,
membername varchar(10) not null,
age int, grade varchar(10) not null,
job varchar(20), point int default 0,
primary key(memberid));

create table product(
productid char(3) not null,
productname varchar(20),
remain int, price int,
maker varchar(20),
primary key(productid),
check (remain >=0 and remain<=10000));

create table `order`(
orderid char(3) not null,
memberid varchar(20),
productid char(3),
remain int, address varchar(30),
orderdate DATE, primary key(orderid));

create table delivery(
deliveryid char(3) not null,
deliveryname varchar(20),
deliveryaddress varchar(100),
deliveryphone varchar(20),
primary key(deliveryid));

alter table newbook add isbn varchar(13);

alter table newbook modify isbn integer;

alter table newbook drop column isbn;

alter table newbook modify bookid integer not null;

alter table newbook add primary key(bookid);

drop table newbook;

drop table neworders;

drop table newcustomer;

insert into newbook(bookid,bookname,publisher,price)
values(11,'스포츠 의학','한술의학서적',90000);

insert into newbook(bookid,bookname,publisher)
values(14,'스포츠 의학','한술의학서적');

update newcustomer set address = '대한민국부산' where custid = 5;

insert into member(memberid,membername,age,grade,job,point)
values('apple','정소화',20,'gold','학생',1000);
insert into member(memberid,membername,age,grade,job,point)
values('banana','김선우',25,'vip','간호사',2500);
insert into member(memberid,membername,age,grade,job,point)
values('carrot','고명석',28,'gold','교사',4500);
insert into member(memberid,membername,age,grade,job,point)
values('orange','김용욱',22,'silver','학생',0);
insert into member(memberid,membername,age,grade,job,point)
values('melon','성원용',35,'gold','회사원',5000);
insert into member(memberid,membername,age,grade,job,point)
values('peach','오형준',null,'silver','의사',300);
insert into member(memberid,membername,age,grade,job,point)
values('pear','채광주',31,'silver','회사원',500);


insert into product(productid,productname,remain,price,maker)
values('p01','그냥만두',5000,4500,'대한식품');
insert into product(productid,productname,remain,price,maker)
values('p02','매운쫄면',2500,5500,'민국푸드');
insert into product(productid,productname,remain,price,maker)
values('p03','쿵떡파이',3600,2600,'한빛제과');
insert into product(productid,productname,remain,price,maker)
values('p04','맛난초콜릿',1250,2500,'한빛제과');
insert into product(productid,productname,remain,price,maker)
values('p05','얼큰라면',2200,1200,'대한식품');
insert into product(productid,productname,remain,price,maker)
values('p06','통통우동',1000,1550,'민국푸드');
insert into product(productid,productname,remain,price,maker)
values('p07','달콤비스킷',1650,1500,'한빛제과');

insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o01','apple','p03',10,'서울시 마포구','2022-01-01');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o02','melon','p01',5,'인천시 계양구','2022-01-10');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o03','banana','p06',45,'경기도 부천시','2022-01-11');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o04','carrot','p02',8,'부산시 금정구','2022-02-01');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o05','melon','p06',36,'경기도 용인시','2022-02-20');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o06','banana','p01',19,'충청북도 보은군','2022-03-02');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o07','apple','p03',22,'서울시 영등포구','2022-03-15');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o08','pear','p02',50,'강원도 춘천시','2022-04-10');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o09','banana','p04',15,'전라남도 목포시','2022-04-11');
insert into `order`(orderid,memberid,productid,remain,address,orderdate)
values('o10','carrot','p03',20,'경기도 안양시','2022-05-22');

select distinct maker from product;


use testdb;

select productname,price as 가격 from product;

select productname , price +500 as "조정 단가" from product;

select productname , remain , price from product where maker= "한빛제과";

select productid, remain,orderdate from `order` where memberid = 'apple' AND remain>=15;

select productid, remain,orderdate,memberid from `order` where memberid = 'apple' or remain>=15;

select membername,age,grade,point from member where membername like '김%';

select memberid,membername,grade from member where memberid like '_____';

select membername from member where age is null;

select membername,grade,age from member order by age desc;

select memberid,productid,remain,orderdate from `order` where remain>=10 order by productid asc, remain desc;

select avg(price) from product;

select sum(remain) as "재고량 합계" from product where maker = '한빛제과';

select count(memberid) as 고객수 from member;

select count(age) as 고객수 from member;

select count(*) as 고객수 from member;

select count(distinct maker) as "제조업체 수" from product;

select productid, sum(remain) as "총주문수량" from `order` group by productid;

select maker, count(*) as 제품수, max(price) as 최고가 from product group by maker;

select maker,count(*) as 제품수 , max(price) as 최고가 from product group by maker having count(*)>=3;

select grade, count(*) as 고객수, avg(point) as 평균적립금 from member group by grade having avg(point) >=1000;

select product.productname from product,`order` where `order`.memberid = 'banana' and product.productid = `order`.productid;

select `order`.productid,`order`.orderdate from member,`order` where member.age >=30 and member.memberid = `order`.memberid;

select product.productname from member,product,`order` where member.membername ='고명석' and member.memberid=`order`.memberid and product.productid = `order`.productid;

select `order`.productid , `order`.orderdate from member inner join `order` on member.memberid = `order`.memberid where member.age >=30;

select member.membername, `order`.productid, `order`.orderdate from member left outer join `order` on member.memberid =`order`.memberid;

select productname,price from product where maker = (select maker from product where productname = '달콤비스킷');

select productname,price from product where productid in (select productid from `order` where memberid = 'banana');

select bookname '제목', char_length(bookname)'문자수',length(bookname)'바이트수' from newBook where publisher='한술의학서적';

select substr(membername, 1, 1)'성', count(*)'인원' from member group by substr(membername,1,1);