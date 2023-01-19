use backdesk

select * from pax_habitacion

select count(ph.id_habitacion) from pax_habitacion ph join establecimiento_habitacion est on ph.id_habitacion = est.id_habitacion where est.id_habitacion = est.id_habitacion

select * from establecimiento_habitacion

create procedure ControlResumenHabitaciones
as
	
	declare @id_hab as int

	declare control_hab cursor for select distinct id_habitacion from pax_habitacion

	open control_hab
	fetch from control_hab into @id_hab
	while @@FETCH_STATUS = 0
	begin 
		insert into cargos(id_habitacion, fecha, importe, concepto) 
		values (@id_hab, getdate(),(select tarifa from establecimiento_habitacion hab where hab.id_habitacion = @id_hab), 'Alojamiento')
		fetch from control_hab into @id_hab
	end
	close control_hab
	deallocate control_hab

	declare @nom_est as char(50)
	declare @nom_est_hab as char(50)
	declare @tipo_hab as char (50)
	declare @cant_ocu as int
	declare @importe as money 
	declare @total as money
	select @total = 0;

	declare est cursor for select nombre_establecimiento from Establecimiento
	open est

	fetch next from est into @nom_est
	while (@@FETCH_STATUS = 0) 
	begin
		print 'Establecimiento: '+rtrim(ltrim(@nom_est));
		declare hab cursor for 
		select distinct est.id_habitacion, nombre_establecimiento, th.descripcion, (select count(ph.id_habitacion) from pax_habitacion ph join establecimiento_habitacion estab on ph.id_habitacion = estab.id_habitacion where estab.id_habitacion = est.id_habitacion), tarifa 
		from establecimiento_habitacion est join tipo_habitacion th on est.id_tipo_habitacion = th.id_tipo_habitacion
		open hab
		fetch next from hab into @id_hab, @nom_est_hab, @tipo_hab, @cant_ocu, @importe
		while @@FETCH_STATUS = 0
		begin
			if(@nom_est = @nom_est_hab) begin
				print char(10)+rtrim(ltrim(@tipo_hab));
				print char(5)+'Ocupadas: '+cast(@cant_ocu as char(10));
				print 'Importe: '+cast((@cant_ocu*@importe) as char(10));
				print '-------------------------------------------';
				select @total = @total + @cant_ocu*@importe;
			end
			fetch next from hab into @id_hab, @nom_est_hab, @tipo_hab, @cant_ocu, @importe
		end
		close hab
		deallocate hab
		print '---------------------------------------------------';
		print 'Total: '+cast(@total as char (10));
		select @total = 0;
		fetch next from est into @nom_est
		print '----------------------------------------------';
	end
	close est
	deallocate est

return 

exec ControlResumenHabitaciones

select * from cargos

delete from cargos

select est.nombre_establecimiento, (select count(emp.id_empleado) from empleados emp where emp.nombre_establecimiento = est.nombre_establecimiento and emp.id_empleado in (select id_empleado from empleado_idioma group by id_empleado having count(id_empleado)>2))
from Establecimiento est

select * from empleado_idioma

select * from empleados

update actividades
set tarifa = tarifa +(tarifa *10/100)
where
id_actividad not in (select id_actividad from pasajero_actividad)


update establecimiento_habitacion
set tarifa = tarifa + (tarifa*10/100)
from establecimiento_habitacion est join tipo_habitacion th on est.id_tipo_habitacion = th.id_tipo_habitacion
where th.descripcion like '%Suite%' and est.id_habitacion not in (select id_habitacion from pax_habitacion)

select * from establecimiento_habitacion
select * from tipo_habitacion

select est.nombre_establecimiento, est.nro_habitacion, count(id_pax) as Huespedes
from establecimiento_habitacion est join pax_habitacion ph on est.id_habitacion = ph.id_habitacion
group by nombre_establecimiento, nro_habitacion
having count(ph.id_pax)>2
order by nombre_establecimiento

select id_habitacion, count(id_pax) from pax_habitacion
group by id_habitacion
having count(id_pax) > 2
order by id_habitacion

alter trigger control_actividad on pasajero_actividad
for insert
as
	declare @id_ins as int
	select @id_ins = i.id_pax from inserted i
	if(@id_ins in (select id_pax from pasajero_actividad)) begin
		print 'Error!! Pasajero ya inscripto en una actividad.'
		rollback
	end
	insert into cargos(id_habitacion, fecha, importe, concepto)
	values ((select id_habitacion from establecimiento_habitacion where id_habitacion = @id_ins), getdate(), 350, (select descripcion from actividades join inserted i on i.id_actividad = actividades.id_actividad))
	commit
return

insert into pasajero_actividad(id_pax, id_actividad) values(10, 1)

select * from pasajero_actividad
select * from actividades
	