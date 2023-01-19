create database EMPRESA

SET DATEFORMAT dmy

use EMPRESA

create table empleado
	    
	(	codigo_empleado int primary key,
		apellido char(50)not null,
		nombre char(50) not null,
		fecha_nacimiento datetime,
		codigo_jefe int not null,
		codigo_oficina int not null,
		numero_documento char(8)not null,
		codigo_documento int not null,
		foreign key (codigo_oficina)
		references oficina(codigo_oficina)
		on update cascade on  delete no action,
		foreign key(codigo_documento)
		references documento(codigo_documento)
		on update cascade on  delete no action	
	);

create table datos_contrato 
	     
	( 	codigo_empleado int primary key,
		fecha_contrato datetime not null,
		cuota money not null,
		ventas money,
		foreign key(codigo_empleado)
		references empleado(codigo_empleado)
		on update cascade on delete no action 
			
	);


create table documento 

		( codigo_documento int primary key identity(1,1),
		  descripcion char(50)

	);


create table producto 
		
	(	codigo_producto int primary  key identity(1001,1),
		descripcion char(50),
		precio_costo money default 0,
		codigo_fabricante int,
		foreign key(codigo_fabricante)
		references fabricante(codigo_fabricante)
		on update cascade on delete no action

	);


create table stock   

	( 	codigo_producto int primary key,
		cantidad numeric not null default 0,
		pto_reposicion numeric default 0,
		foreign key (codigo_producto)
		references producto(codigo_producto)
		on update cascade on delete no action			

	);


create table fabricante
	
	 (	 codigo_fabricante int primary key identity(1,1),
		 razon_social char(50) not null

	);


create table precio_venta

	(	codigo_producto int ,
		codigo_lista int ,
		precio money not null default 0,
		primary key(codigo_producto,codigo_lista),
		foreign key(codigo_producto)
		references producto(codigo_producto)
		on update cascade on delete no action,
		foreign key(codigo_lista)
		references lista(codigo_lista)
		on update cascade on delete no action

	);


create table cliente 

	(	codigo_cliente int primary key identity(1,1),
		codigo_lista int not null,
		razon_social char(50) not null,
		foreign key(codigo_lista)
		references lista(codigo_lista)
		on update cascade on delete no action


	);


create table pedido

	(	codigo_pedido int primary key identity(1,1),
		fecha_pedido datetime not null,
		codigo_empleado int not null,
		codigo_cliente int not null,
		foreign key(codigo_empleado)
		references empleado(codigo_empleado)
		on update cascade on delete no action,
		foreign key(codigo_cliente)
		references cliente(codigo_cliente)
		on update cascade on delete no action				  

	);


create table  detalle_pedido 
	
	(	codigo_pedido int,
		numero_linea int,
		codigo_producto int not null,
		primary key(codigo_pedido,numero_linea),
		foreign key(codigo_pedido)
		references pedido(codigo_pedido) 
		on update cascade on delete no action,
		foreign key(codigo_producto )
		references producto(codigo_producto)
		on update cascade on delete no action

	);


create table lista
	
	(	codigo_lista int primary key identity(1,1),
		descripcion char(20) not null,
		ganancia_porcentaje numeric(5,2) not null
			
	);


create table oficina

	(	codigo_oficina int primary key identity(1,1),
		codigo_director int,
		descripcion char(50) not null
			
	);


insert into documento(descripcion)values('Documento Nacional de Identidad')
insert into documento(descripcion)values('Cédula de Identidad')
insert into documento(descripcion)values('Pasaporte')
insert into documento(descripcion)values('Libreta de Enrolamiento')

select * from documento 

insert into oficina(descripcion,codigo_director)values('Presidencia',101)
insert into oficina(descripcion,codigo_director)values('Gerencia',102)
insert into oficina(descripcion,codigo_director)values('Ventas Interior',104)
insert into oficina(descripcion)values('Ventas Exterior')

select * from oficina 

insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(101,'Viguer','Antonio','20/05/56',12456897,0,1,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(102,'Jaumes','Alvaro','30/03/55',12654897,101,2,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(103,'Rovira','Juan','21/06/60',15789546,102,3,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(104,'Gonzales','Analia','23/04/58',13456789,102,3,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(105,'Pantalla','Marcela','02/12/63',14875987,102,3,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(106,'Bustamante','Jorge','05/05/63',4756984,102,3,2)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(107,'Sunta','Maria','21/06/70',16789547,101,2,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(108,'Victor','Juan','18/09/66',13854789,107,4,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(109,'Alvarez ','Adriana','30/09/56',12465879,107,4,1)
insert into empleado(codigo_empleado,apellido,Nombre,fecha_nacimiento,numero_documento,codigo_jefe,codigo_oficina,codigo_documento)values(110,'Clavel','Maria','02/07/64',99875987,107,4,3)

select * from empleado

insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(101,'20/01/98',57000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(102,'15/03/98',57000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(103,'10/06/99',57000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(104,'21/04/97',45000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(105,'13/05/98',45000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(106,'21/06/99',45000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(107,'14/06/97',45000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(108,'15/03/95',120000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(109,'12/03/87',120000)
insert into datos_contrato(codigo_empleado,fecha_contrato,cuota)values(110,'15/06/88',90000)

select * from datos_contrato

insert into fabricante(razon_social)values('ABC Comercial')
insert into fabricante(razon_social)values('General de Negocios S.A.')
insert into fabricante(razon_social)values('Tomasti Hnos.')
insert into fabricante(razon_social)values('Basic')
insert into fabricante(razon_social)values('Ferreteria Sudamericana')
insert into fabricante(razon_social)values('Pampas S.R.L.')

select * from fabricante

insert into lista(descripcion,ganancia_porcentaje)values('Mayorista',20)
insert into lista(descripcion,ganancia_porcentaje)values('Minorista',30)

select * from lista

insert into producto(descripcion,precio_costo,codigo_fabricante)values('Arandela',0.50,1)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Bisagra',1,2)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Extractor',135,3)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Junta',21,2)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Cubo',350,4)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Perno',21,5)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Red',821,3)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Escofina',35,2)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Bomba V6',1012,1)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Rele',35,3)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Bagueta A3',48,5)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Ventilador',289,1)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Linterna 2X',28,2)
insert into producto(descripcion,precio_costo,codigo_fabricante)values('Linterna 3X',38,2)

select * from producto


insert into stock(codigo_producto,cantidad,pto_reposicion)values(1001,1000,1000)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1002,1500,1000)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1003,450,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1004,830,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1005,180,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1006,1000,1000)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1007,500,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1008,300,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1009,450,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1010,320,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1011,750,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1012,450,1000)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1013,150,500)
insert into stock(codigo_producto,cantidad,pto_reposicion)values(1014,300,500)

select * from stock

insert into precio_venta(codigo_producto,codigo_lista)values(1001,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1001,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1002,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1002,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1003,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1003,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1004,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1004,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1005,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1005,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1006,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1006,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1007,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1008,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1009,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1010,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1010,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1011,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1011,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1012,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1012,2)
insert into precio_venta(codigo_producto,codigo_lista)values(1013,1)
insert into precio_venta(codigo_producto,codigo_lista)values(1014,1)

select * from precio_venta

insert into cliente(codigo_lista,razon_social)values(1,'Luis garcia Antón')
insert into cliente(codigo_lista,razon_social)values(1,'Jaime LLorens')
insert into cliente(codigo_lista,razon_social)values(1,'El Triángulo')
insert into cliente(codigo_lista,razon_social)values(1,'Bujes y Pernos')
insert into cliente(codigo_lista,razon_social)values(1,'Carlos Tena')
insert into cliente(codigo_lista,razon_social)values(2,'La Manivela')
insert into cliente(codigo_lista,razon_social)values(2,'Juan Bolto')
insert into cliente(codigo_lista,razon_social)values(2,'Alvarez Hnos.')
insert into cliente(codigo_lista,razon_social)values(1,'ORSAN S.A.')
insert into cliente(codigo_lista,razon_social)values(2,'Cristóbal García')
insert into cliente(codigo_lista,razon_social)values(1,'La Fontella')
insert into cliente(codigo_lista,razon_social)values(1,'Sunshine Ready')
insert into cliente(codigo_lista,razon_social)values(2,'San Antonio')
insert into cliente(codigo_lista,razon_social)values(2,'Castelnuovo S.A.')
insert into cliente(codigo_lista,razon_social)values(1,'BlueMoon')
insert into cliente(codigo_lista,razon_social)values(1,'Las Cabañas')
insert into cliente(codigo_lista,razon_social)values(2,'Electrosur')

select * from cliente

insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('15/03/02',101,1)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('15/03/02',101,2)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('15/03/02',102,3)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('16/03/02',104,4)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('16/03/02',104,1)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('16/03/02',104,5)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('16/03/02',105,4)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('21/03/02',108,7)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('22/03/02',108,6)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('22/03/02',104,6)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('22/03/02',101,1)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('22/03/02',110,4)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('01/04/02',110,12)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('01/04/02',102,12)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('12/04/02',104,15)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('12/04/02',108,15)
insert into pedido(fecha_pedido,codigo_empleado,codigo_cliente)values('14/04/02',101,12)


select * from pedido

Alter table detalle_pedido add cantidad integer;
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(1,1,1003,10)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(1,2,1005,12)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(1,3,1007,45)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(2,1,1001,78)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(3,1,1008,32)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(3,2,1009,5)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(3,3,1003,46)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(4,1,1004,12)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(4,2,1005,45)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(5,1,1002,23)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(6,1,1007,30)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(6,2,1008,14)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(7,1,1006,7)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(7,2,1005,65)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(7,3,1004,120)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(8,1,1004,32)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(8,2,1006,74)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(9,1,1009,115)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(9,2,1003,89)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(10,1,1004,10)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(10,2,1001,12)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(11,1,1003,12)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(11,2,1008,6)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(11,3,1009,38)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(12,1,1005,65)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(12,2,1001,56)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(12,3,1009,45)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(12,4,1004,18)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(12,5,1003,14)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(13,1,1011,21)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(13,2,1012,32)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(14,1,1013,100)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(14,2,1014,6)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(14,3,1010,18)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(15,1,1009,9)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(15,2,1012,32)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(16,1,1014,5)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(17,1,1011,10)
insert into detalle_pedido(codigo_pedido,numero_linea,codigo_producto,cantidad)values(17,2,1001,12)

select * from detalle_pedido;

alter table cliente add limite_credito money;

alter table lista add check (ganancia_porcentaje > 0);

alter table oficina add ciudad char(50);

alter table oficina drop column ciudad;

alter table pedido add fecha_entrega as (fecha_pedido+30);

select descripcion from oficina;

select descripcion, precio_costo, precio_costo*1.21 as precio_con_IVA from producto; 

select apellido, nombre, fecha_nacimiento, DATEDIFF(yy, fecha_nacimiento, GETDATE()) as edad from empleado;

select apellido, nombre from empleado where codigo_jefe <> 0;

select apellido, nombre from empleado where nombre = 'Maria' order by apellido;

select codigo_cliente from cliente where razon_social like 'L%' order by codigo_cliente;

select * from pedido where DATEPART(month, fecha_pedido) = 3 order by fecha_pedido;  

select * from oficina where codigo_director is not null;

select top 4 * from producto order by precio_costo asc;

select top 3 codigo_empleado from datos_contrato order by cuota desc;

select descripcion, razon_social, cantidad from producto join fabricante on producto.codigo_fabricante = fabricante.codigo_fabricante join stock on producto.codigo_producto = stock.codigo_producto order by razon_social, descripcion;

select codigo_pedido, fecha_pedido, apellido, razon_social from pedido join empleado on pedido.codigo_empleado = empleado.codigo_empleado join cliente on pedido.codigo_cliente = cliente.codigo_cliente;

select empleado.apellido as subordinado, cuota, descripcion, e.apellido as jefe from empleado join datos_contrato on empleado.codigo_empleado = datos_contrato.codigo_empleado join oficina on empleado.codigo_oficina = oficina.codigo_oficina join empleado e on e.codigo_empleado = empleado.codigo_jefe order by cuota desc;

select distinct razon_social from cliente join pedido on cliente.codigo_cliente = pedido.codigo_cliente where DATEPART(month, fecha_pedido) = 4;

select distinct descripcion from producto join detalle_pedido on detalle_pedido.codigo_producto = producto.codigo_producto join pedido on detalle_pedido.codigo_pedido = pedido.codigo_pedido where DATEPART(month, fecha_pedido) = 3; 

select apellido, nombre from empleado join datos_contrato on empleado.codigo_empleado = datos_contrato.codigo_empleado where DATEDIFF(yy, fecha_contrato, GETDATE()) > 10;

select razon_social from cliente join lista on cliente.codigo_lista = lista.codigo_lista where lista.descripcion = 'Mayorista' order by razon_social;

select * from lista

update precio_venta set precio=(producto.precio_costo + (producto.precio_costo*lista.ganancia_porcentaje/100)) from producto, lista, precio_venta where producto.codigo_producto = precio_venta.codigo_producto and precio_venta.codigo_lista = lista.codigo_lista;
select * from precio_venta;

select razon_social from fabricante where codigo_fabricante not in (select distinct codigo_fabricante from producto);
delete from fabricante where codigo_fabricante not in (select distinct codigo_fabricante from producto);

select codigo_cliente, razon_social from cliente where codigo_cliente not in (select distinct codigo_cliente from pedido);
delete from cliente where codigo_cliente not in (select distinct codigo_cliente from pedido);

update datos_contrato set cuota=cuota*1.05 where DATEPART(year, fecha_contrato) < 1999;
select * from datos_contrato;

update empleado set codigo_empleado=112 where codigo_empleado=110;
select * from empleado;

update producto set precio_costo=precio_costo*1.1;

update stock set pto_reposicion=600 from stock, producto, fabricante where stock.codigo_producto = producto.codigo_producto and producto.codigo_fabricante = fabricante.codigo_fabricante and fabricante.razon_social = 'Tomasti HNOS.'; 

select AVG(precio_costo) from producto join fabricante on producto.codigo_fabricante = fabricante.codigo_fabricante where fabricante.razon_social = 'ABC Comercial';

select fecha_pedido from pedido order by fecha_pedido asc;

select descripcion, count(codigo_empleado) as cantidadEmpleados from oficina join empleado on oficina.codigo_oficina = empleado.codigo_oficina group by descripcion;

select nombre, apellido from empleado join oficina on empleado.codigo_oficina = oficina.codigo_oficina where oficina.descripcion <> 'Ventas Exterior';

update datos_contrato set ventas = 0;
update datos_contrato set ventas = (select sum(precio * cantidad) from datos_contrato dc, detalle_pedido dp, pedido p, precio_venta pv
where p.codigo_pedido = dp.codigo_pedido and dp.codigo_producto = pv.codigo_producto and datos_contrato.codigo_empleado = p.codigo_empleado);

select distinct descripcion from oficina join empleado on oficina.codigo_oficina = empleado.codigo_oficina 
where codigo_empleado in (select codigo_empleado from datos_contrato where ventas > cuota*1.1)

select * from datos_contrato;

select avg(cuota) as promedioCuota, avg(ventas) as promedioVentas from datos_contrato;

select razon_social, count(codigo_pedido) as cantPedidos from cliente c, pedido p where c.codigo_cliente = p.codigo_cliente group by razon_social;

select descripcion from producto p, detalle_pedido dp, pedido pe 
where pe.codigo_pedido = dp.codigo_pedido and dp.codigo_producto = p.codigo_producto and
datepart(month, pe.fecha_pedido) = 3 group by dp.codigo_producto, descripcion having sum(dp.cantidad) < 200;

select descripcion, (dp.codigo_pedido)*cantidad as Pedidos_En_Marzo  from producto p, pedido pe, detalle_pedido dp 
where pe.codigo_pedido = dp.codigo_pedido and dp.codigo_producto = p.codigo_producto and datepart(month, pe.fecha_pedido) = 3
group by descripcion, cantidad;

select count(codigo_producto) as ProductosAReponer from stock where cantidad < pto_reposicion;

select razon_social from cliente c, pedido p, empleado e where c.codigo_cliente = p.codigo_cliente and p.codigo_empleado = e.codigo_empleado and e.apellido = 'Gonzales' and e.nombre = 'Analia';
select * from empleado;

select distinct razon_social from cliente 
				join pedido on cliente.codigo_cliente = pedido.codigo_cliente 
				join detalle_pedido on pedido.codigo_pedido = detalle_pedido.codigo_pedido 
				join precio_venta on detalle_pedido.codigo_producto = precio_venta.codigo_producto 
				join lista on precio_venta.codigo_lista = lista.codigo_lista 
				where cantidad * precio_venta.precio + (precio_venta.precio*lista.ganancia_porcentaje/100) > 850; 


select razon_social from fabricante where fabricante.codigo_fabricante 
not in (select codigo_fabricante from producto p, detalle_pedido dp, pedido pe 
where p.codigo_producto = dp.codigo_producto and dp.codigo_pedido = pe.codigo_pedido and datepart(month, pe.fecha_pedido) = 4);

select distinct * from producto where codigo_producto in 
(select codigo_producto from detalle_pedido dp, pedido p where
dp.codigo_pedido = p.codigo_pedido and datepart(month, p.fecha_pedido) = 3 group by codigo_producto having sum(cantidad) >= 70)

select * from producto where codigo_producto not in 
(select codigo_producto from precio_venta pv, lista l where
pv.codigo_lista = l.codigo_lista and l.descripcion = 'Minorista');

select razon_social from cliente where codigo_cliente not in 
(select codigo_cliente from pedido p, detalle_pedido dp, empleado e, precio_venta pv where
p.codigo_pedido = dp.codigo_pedido and p.codigo_empleado = e.codigo_empleado and 
dp.codigo_producto = pv.codigo_producto and e.nombre = 'Adriana' and e.apellido = 'Alvarez' and
pv.precio*dp.cantidad > 1000);

create view productos_fabricantes as
		select fabricante.razon_social, producto.descripcion, stock.cantidad from producto
		join stock on producto.codigo_producto = stock.codigo_producto
		join fabricante on fabricante.codigo_fabricante = producto.codigo_fabricante;
		
select * from productos_fabricantes order by razon_social;		


create trigger control_pedidos on detalle_pedido 
for insert 
as
	declare @stock int
	select @stock = stock.cantidad from stock join inserted on inserted.codigo_producto = stock.codigo_producto
	where inserted.codigo_producto = stock.codigo_producto
	if (@stock>=(select cantidad from inserted))
		update stock set cantidad = stock.cantidad - inserted.cantidad from stock join inserted 
		on inserted.codigo_producto = stock.codigo_producto where inserted.codigo_producto = stock.codigo_producto
	else
	begin 
		raiserror('hay menos productos en stock de los solicitados en el pedido.', 16, 1)
		rollback transaction
	end
		
insert into detalle_pedido values(17, 3, 1001, 500);
insert into detalle_pedido values(17, 4, 1005, 500);

create trigger ingreso_stock on producto for insert 
as 
begin
	insert into stock(codigo_producto, cantidad, pto_reposicion)
		select inserted.codigo_producto, 0, 50 from inserted
end

alter table producto enable trigger ingreso_stock

create procedure compra_producto (@nom varchar(50), @cant int, @cod_fab int, @precio money)
as
begin 
		if((select count(descripcion) from producto p where p.descripcion = @nom) = 0)
		begin 
			insert into producto(descripcion, precio_costo, codigo_fabricante)
			values (@nom, @precio, @cod_fab)
		end

		update stock set cantidad = @cant, pto_reposicion = @cant*2 from stock
		join producto on stock.codigo_producto = producto.codigo_producto
		where producto.descripcion = @nom
end

exec compra_producto 'Ventilador', 5, 1, 8

select * from stock

create table auditoria_producto (
									codigo_producto int,
									descripcion varchar(50), 
									precio_costo money, 
									codigo_fabricante int, 
									fecha_actualizacion datetime,
									usuario varchar(50)
								)


create trigger modif_producto on producto for update as
begin
	insert into auditoria_producto(codigo_producto, descripcion, precio_costo, codigo_fabricante, fecha_actualizacion, usuario)
	select del.codigo_producto, del.descripcion, del.precio_costo, del.codigo_fabricante, getdate(), USER_NAME() from deleted del
end

alter table producto enable trigger modif_producto

select * from producto
select * from auditoria_producto

update producto set precio_costo=5 where codigo_producto=1001

select * from precio_venta
select * from auditoria_producto

alter trigger nuevo_producto on producto for insert as
begin 
	insert into precio_venta (codigo_producto, codigo_lista, precio)
	select ins.codigo_producto, 1, ins.precio_costo+ins.precio_costo*l.ganancia_porcentaje/100 from inserted ins, lista l
	where l.codigo_lista = 1

	insert into precio_venta (codigo_producto, codigo_lista, precio)
	select ins.codigo_producto, 2, ins.precio_costo+ins.precio_costo*l.ganancia_porcentaje/100 from inserted ins, lista l 
	where l.codigo_lista = 2
end

insert into producto (descripcion, precio_costo, codigo_fabricante)
values ('Destrornillador', 120, 5)


declare @oficina as char(50)
declare @cod_oficina as int
declare @cod_director as int
declare @nom_director as char(50)
declare @ape_director as char(50)

declare cursor_oficina cursor for 
select o.descripcion, o.codigo_oficina, d.nombre, d.apellido, o.codigo_director
from oficina o left join empleado d on o.codigo_director = d.codigo_empleado

/* variables para el cursor de empleados */
declare @cod_empleado as int
declare @nom_empleado as char(50)
declare @ape_empleado as char (50)

open cursor_oficina
fetch next from cursor_oficina into @oficina, @cod_oficina, @nom_director, @ape_director, @cod_director
while @@FETCH_STATUS = 0
	begin 
		print char(13)+'Oficina: '+@oficina;
		print 'Director: '+rtrim(ltrim(@nom_director))+', '+rtrim(ltrim(@ape_director));
		print 'Empleados: ';
		declare cursor_empleados cursor for
		select distinct e.apellido, e.nombre, e.codigo_empleado from empleado e, oficina o
		where e.codigo_oficina = @cod_oficina
		open cursor_empleados
		fetch next from cursor_empleados into @ape_empleado, @nom_empleado, @cod_empleado
		while @@FETCH_STATUS = 0
			begin
				if @cod_director <> @cod_empleado or @cod_director is null
					begin
						print rtrim(ltrim(@nom_empleado))+', '+rtrim(ltrim(@ape_empleado))
					end
				fetch next from cursor_empleados into @ape_empleado, @nom_empleado, @cod_empleado
			end
		close cursor_empleados
		deallocate cursor_empleados
		fetch next from cursor_oficina into @oficina, @cod_oficina, @nom_director, @ape_director, @cod_director
	end
close cursor_oficina
deallocate cursor_oficina


create procedure nuevoProducto
	(@descripcion varchar(50),
	@codigo_fabricante int,
	@precio_costo money)

as
	begin transaction
	/* insertar nuevo articulo */
		insert into producto (descripcion, precio_costo, codigo_fabricante)
		values (@descripcion, @precio_costo, @codigo_fabricante)

		if @@error <> 0
		begin
			rollback transaction
			print 'No se pudo agregar el producto'
			return
		end
		commit transaction

return					

exec nuevoProducto Tornillo, 36, 8

select * from producto


create procedure control_stock (@descripcion as varchar(50)=NULL)
as
	declare @pedir as int
	if(@descripcion is NULL) begin
		declare stock cursor for
		select p.descripcion, (s.pto_reposicion - s.cantidad) 
		from producto p join stock s on p.codigo_producto = s.codigo_producto
		where (s.pto_reposicion - s.cantidad) > 0 order by p.descripcion
	end
	else
	begin
		declare stock cursor for
		select p.descripcion, (s.pto_reposicion - s.cantidad) 
		from producto p join stock s on p.codigo_producto = s.codigo_producto
		where (s.pto_reposicion - s.cantidad) > 0 and @descripcion = p.descripcion
	end

	open stock
	fetch next from stock into @descripcion, @pedir

	while (@@FETCH_STATUS = 0) begin
		print rtrim(ltrim(@descripcion))+', pedir: '+cast(@pedir as char(10));
		fetch next from stock into @descripcion, @pedir
	end
	close stock
	deallocate stock

return

exec control_stock 'Tornillo'

create procedure ver_productos (@descripcion as varchar(50)=NULL)
as
	if(@descripcion is null) begin
		select * from producto
	end
	else
	begin
		select * from producto where producto.descripcion like @descripcion
	end

return

exec ver_productos 'Escofina'

select distinct p.descripcion, p.codigo_fabricante from producto p
join detalle_pedido dp on p.codigo_producto = dp.codigo_producto join pedido pe on dp.codigo_pedido = pe.codigo_pedido
where dp.cantidad > 70 and DATEPART(month, pe.fecha_pedido) = 3


