INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (1, 1001, 'Proveedor A', '1234567890', 'Apellido A', 'proveedora@example.com', 'Tipo A');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (2, 1002, 'Proveedor B', '9876543210', 'Apellido B', 'proveedorb@example.com', 'Tipo B');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (3, 1003, 'Proveedor C', '5555555555', 'Apellido C', 'proveedorc@example.com', 'Tipo C');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (4, 1004, 'Proveedor D', '1111111111', 'Apellido D', 'proveedord@example.com', 'Tipo D');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (5, 1005, 'Proveedor E', '2222222222', 'Apellido E', 'proveedore@example.com', 'Tipo E');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (6, 1006, 'Proveedor F', '3333333333', 'Apellido F', 'proveedorf@example.com', 'Tipo F');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (7, 1007, 'Proveedor G', '4444444444', 'Apellido G', 'proveedorg@example.com', 'Tipo G');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (8, 1008, 'Proveedor H', '6666666666', 'Apellido H', 'proveedorh@example.com', 'Tipo H');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (9, 1009, 'Proveedor I', '7777777777', 'Apellido I', 'proveedori@example.com', 'Tipo I');

INSERT INTO Provedor (Num_provedor, idProvedor, Nombre, Num_tel, Apellido, Mail, tipo_proveedor)
VALUES (10, 1010, 'Proveedor J', '9999999999', 'Apellido J', 'proveedorj@example.com', 'Tipo J');

--------------------------------------------------------------------------------------------------

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (1, 10001, 50.25, 10.5, '2024-04-01', 123456789, 'Lugar A', 1);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (2, 10002, 100.75, 5.2, '2024-04-02', 987654321, 'Lugar B', 2);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (3, 10003, 75.0, 8.9, '2024-04-03', 555555555, 'Lugar C', 3);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (4, 10004, 120.5, 15.0, '2024-04-04', 111111111, 'Lugar D', 4);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (5, 10005, 90.25, 6.8, '2024-04-05', 222222222, 'Lugar E', 5);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (6, 10006, 55.0, 12.3, '2024-04-06', 333333333, 'Lugar F', 6);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (7, 10007, 80.75, 9.7, '2024-04-07', 444444444, 'Lugar G', 7);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (8, 10008, 95.5, 7.5, '2024-04-08', 666666666, 'Lugar H', 8);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (9, 10009, 115.25, 11.2, '2024-04-09', 777777777, 'Lugar I', 9);

INSERT INTO Orden_provedor (Num_orden, Id_Orden_provedor, precio_Orden_provedor, cantidad_kg, fecha, Cuit, Lugar_entrega, Provedor)
VALUES (10, 10010, 70.0, 5.9, '2024-04-10', 999999999, 'Lugar J', 10);

--------------------------------------------------------------------------------------------------

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (1, 10001, 'Producto A', 'Descripción A', 50.25, '2024-04-01', 10.5, 1);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (2, 10002, 'Producto B', 'Descripción B', 100.75, '2024-04-02', 5.2, 2);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (3, 10003, 'Producto C', 'Descripción C', 75.0, '2024-04-03', 8.9, 3);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (4, 10004, 'Producto D', 'Descripción D', 120.5, '2024-04-04', 15.0, 4);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (5, 10005, 'Producto E', 'Descripción E', 90.25, '2024-04-05', 6.8, 5);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (6, 10006, 'Producto F', 'Descripción F', 55.0, '2024-04-06', 12.3, 6);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (7, 10007, 'Producto G', 'Descripción G', 80.75, '2024-04-07', 9.7, 7);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (8, 10008, 'Producto H', 'Descripción H', 95.5, '2024-04-08', 7.5, 8);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (9, 10009, 'Producto I', 'Descripción I', 115.25, '2024-04-09', 11.2, 9);

INSERT INTO Producto (Num_producto, idProducto, Nombre, Descripcion, Precio, Fecha_vencimiento, Cantidad_kg, Orden_producto_Num_orden)
VALUES (10, 10010, 'Producto J', 'Descripción J', 70.0, '2024-04-10', 5.9, 10);

--------------------------------------------------------------------------------------------------

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (1, 10001, 'John', 'Doe', '123456789', '123 Main St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (2, 10002, 'Jane', 'Smith', '987654321', '456 Elm St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (3, 10003, 'Michael', 'Johnson', '555555555', '789 Oak St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (4, 10004, 'Emily', 'Williams', '111111111', '321 Pine St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (5, 10005, 'David', 'Brown', '222222222', '654 Maple St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (6, 10006, 'Sarah', 'Jones', '333333333', '987 Cedar St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (7, 10007, 'Daniel', 'Garcia', '444444444', '654 Oak St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (8, 10008, 'Jessica', 'Lopez', '666666666', '321 Elm St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (9, 10009, 'Christopher', 'Martinez', '777777777', '789 Pine St');

INSERT INTO Cliente (num_Cliente, idCliente, Nombre, Apellido, Telefono, Direccion)
VALUES (10, 10010, 'Amanda', 'Taylor', '999999999', '987 Maple St');

--------------------------------------------------------------------------------------------------

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C001', 10001, 'John', 'Doe', '123456789', 'Padre', 'john.doe@example.com', '123 Main St', '555-123-4567', 'Ciudad A');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C002', 10002, 'Jane', 'Smith', '987654321', 'Madre', 'jane.smith@example.com', '456 Elm St', '555-987-6543', 'Ciudad B');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C003', 10003, 'Michael', 'Johnson', '555555555', 'Hermano', 'michael.johnson@example.com', '789 Oak St', '555-555-5555', 'Ciudad C');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C004', 10004, 'Emily', 'Williams', '111111111', 'Hermana', 'emily.williams@example.com', '321 Pine St', '555-111-1111', 'Ciudad D');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C005', 10005, 'David', 'Brown', '222222222', 'Amigo', 'david.brown@example.com', '654 Maple St', '555-222-2222', 'Ciudad E');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C006', 10006, 'Sarah', 'Jones', '333333333', 'Amiga', 'sarah.jones@example.com', '987 Cedar St', '555-333-3333', 'Ciudad F');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C007', 10007, 'Daniel', 'Garcia', '444444444', 'Primo', 'daniel.garcia@example.com', '654 Oak St', '555-444-4444', 'Ciudad G');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C008', 10008, 'Jessica', 'Lopez', '666666666', 'Tía', 'jessica.lopez@example.com', '321 Elm St', '555-666-6666', 'Ciudad H');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C009', 10009, 'Christopher', 'Martinez', '777777777', 'Tío', 'christopher.martinez@example.com', '789 Pine St', '555-777-7777', 'Ciudad I');

INSERT INTO Contacto_Emergencia (numContacto, idContacto, Nombre, Apellido, Telefono, Parentesco, Mail, Domicilio, Trabajo_tel, Ciudad)
VALUES ('C010', 10010, 'Amanda', 'Taylor', '999999999', 'Vecino', 'amanda.taylor@example.com', '987 Maple St', '555-999-9999', 'Ciudad J');

--------------------------------------------------------------------------------------------------

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (1, 10001, 123456789, 'Gerente', 'Lunes a Viernes, 9am-5pm', 5000.00, 'John', 'Doe', '123 Main St', '555-123-4567', 'C001', 'SeguroSalud', 'SS001', 'C001');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (2, 10002, 987654321, 'Asistente', 'Lunes a Viernes, 9am-5pm', 3000.00, 'Jane', 'Smith', '456 Elm St', '555-987-6543', 'C002', 'SeguroVida', 'SV001', 'C002');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (3, 10003, 555555555, 'Analista', 'Lunes a Viernes, 9am-5pm', 4000.00, 'Michael', 'Johnson', '789 Oak St', '555-555-5555', 'C003', 'SeguroSalud', 'SS002', 'C003');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (4, 10004, 111111111, 'Recepcionista', 'Lunes a Viernes, 9am-5pm', 2500.00, 'Emily', 'Williams', '321 Pine St', '555-111-1111', 'C004', 'SeguroVida', 'SV002', 'C004');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (5, 10005, 222222222, 'Técnico', 'Lunes a Viernes, 9am-5pm', 3500.00, 'David', 'Brown', '654 Maple St', '555-222-2222', 'C005', 'SeguroSalud', 'SS003', 'C005');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (6, 10006, 333333333, 'Supervisor', 'Lunes a Viernes, 9am-5pm', 4500.00, 'Sarah', 'Jones', '987 Cedar St', '555-333-3333', 'C006', 'SeguroVida', 'SV003', 'C006');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (7, 10007, 444444444, 'Asistente', 'Lunes a Viernes, 9am-5pm', 3000.00, 'Daniel', 'Garcia', '654 Oak St', '555-444-4444', 'C007', 'SeguroSalud', 'SS004', 'C007');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (8, 10008, 555555555, 'Analista', 'Lunes a Viernes, 9am-5pm', 4000.00, 'Maria', 'Lopez', '789 Pine St', '555-555-5555', 'C008', 'SeguroVida', 'SV004', 'C008');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (9, 10009, 666666666, 'Técnico', 'Lunes a Viernes, 9am-5pm', 3500.00, 'Carlos', 'Gonzalez', '654 Elm St', '555-666-6666', 'C009', 'SeguroSalud', 'SS005', 'C009');

INSERT INTO Empleado (Num_empleado, idempleado, DNI, Puesto, Horario, Sueldo, Nombre, Apellido, Direccion, Telefono, Numero_emergencia, Obra_social, Num_obra_social, Contacto_Emergencia_numContacto)
VALUES (10, 10010, 777777777, 'Supervisor', 'Lunes a Viernes, 9am-5pm', 4500.00, 'Laura', 'Rodriguez', '987 Maple St', '555-777-7777', 'C010', 'SeguroVida', 'SV005', 'C010');

--------------------------------------------------------------------------------------------------

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (1, 'Venta', '2024-04-01', 100.50, 'Tarjeta de crédito', 10001);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (2, 'Compra', '2024-04-02', 250.75, 'Transferencia bancaria', 10002);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (3, 'Venta', '2024-04-03', 75.20, 'Efectivo', 10003);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (4, 'Compra', '2024-04-04', 300.00, 'Tarjeta de débito', 10004);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (5, 'Venta', '2024-04-05', 80.10, 'Efectivo', 10005);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (6, 'Compra', '2024-04-06', 150.25, 'Transferencia bancaria', 10006);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (7, 'Venta', '2024-04-07', 95.80, 'Tarjeta de crédito', 10007);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (8, 'Compra', '2024-04-08', 200.50, 'Tarjeta de crédito', 10008);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (9, 'Venta', '2024-04-09', 120.75, 'Efectivo', 10009);

INSERT INTO Factura (Num_factura, Tipo_factura, Fecha, Total, Medio_de_pago, idFactura)
VALUES (10, 'Compra', '2024-04-10', 180.90, 'Transferencia bancaria', 10010);

--------------------------------------------------------------------------------------------------

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (1, 1001, '2024-04-01 10:00:00', 'Pedido de productos A', 'Venta', 10, 1);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (2, 1002, '2024-04-02 11:30:00', 'Pedido de productos B', 'Venta', 9, 2);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (3, 1003, '2024-04-03 14:15:00', 'Pedido de productos C', 'Venta', 8, 3);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (4, 1004, '2024-04-04 09:45:00', 'Pedido de productos D', 'Venta', 7, 4);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (5, 1005, '2024-04-05 16:30:00', 'Pedido de productos E', 'Venta', 6, 5);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (6, 1006, '2024-04-06 13:00:00', 'Pedido de productos F', 'Venta', 5, 6);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (7, 1007, '2024-04-07 10:45:00', 'Pedido de productos G', 'Venta', 4, 7);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (8, 1008, '2024-04-08 15:20:00', 'Pedido de productos H', 'Venta', 3, 8);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (9, 1009, '2024-04-09 12:30:00', 'Pedido de productos I', 'Venta', 2, 9);

INSERT INTO Pedido (numPedido, idPedido, Fecha, descripcion, tipoPedido, Cliente, Empleado)
VALUES (10, 1010, '2024-04-10 14:45:00', 'Pedido de productos J', 'Venta', 1, 10);

--------------------------------------------------------------------------------------------------

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (5, 50.00, 10.50, 10.00, 1, 1);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (3, 30.00, 6.30, 10.00, 2, 2);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (2, 20.00, 4.20, 10.00, 3, 3);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (4, 40.00, 8.40, 10.00, 4, 4);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (6, 60.00, 12.60, 10.00, 5, 5);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (1, 10.00, 2.10, 10.00, 6, 6);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (4, 40.00, 8.40, 10.00, 7, 7);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (2, 20.00, 4.20, 10.00, 8, 8);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (3, 30.00, 6.30, 10.00, 9, 9);

INSERT INTO Detalle_Pedido (Cantidad_productos, Subtotal, IVA, Precio_unitario, Factura_Num_factura, Pedido)
VALUES (5, 50.00, 10.50, 10.00, 10, 10);

--------------------------------------------------------------------------------------------------

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (1, 1001, 'Calle Principal 123', '09:00:00', '18:00:00', 'Tienda A', 10, 'Ciudad A', 'País A', '2020-01-01 00:00:00', 'Descripción A', '123-456-7890');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (2, 1002, 'Avenida Central 456', '10:00:00', '19:00:00', 'Tienda B', 8, 'Ciudad B', 'País B', '2019-05-10 09:00:00', 'Descripción B', '987-654-3210');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (3, 1003, 'Plaza Principal 789', '08:30:00', '17:30:00', 'Tienda C', 12, 'Ciudad C', 'País C', '2021-03-15 10:30:00', 'Descripción C', '456-789-0123');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (4, 1004, 'Calle Secundaria 321', '08:00:00', '17:00:00', 'Tienda D', 6, 'Ciudad D', 'País D', '2022-07-20 14:45:00', 'Descripción D', '789-012-3456');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (5, 1005, 'Avenida Principal 987', '09:30:00', '18:30:00', 'Tienda E', 15, 'Ciudad E', 'País E', '2023-09-05 12:00:00', 'Descripción E', '012-345-6789');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (6, 1006, 'Plaza Central 654', '10:30:00', '19:30:00', 'Tienda F', 9, 'Ciudad F', 'País F', '2022-02-14 16:15:00', 'Descripción F', '345-678-9012');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (7, 1007, 'Calle Principal 012', '09:00:00', '18:00:00', 'Tienda G', 11, 'Ciudad G', 'País G', '2021-06-30 13:30:00', 'Descripción G', '678-901-2345');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (8, 1008, 'Avenida Central 678', '10:00:00', '19:00:00', 'Tienda H', 7, 'Ciudad H', 'País H', '2023-03-25 11:45:00', 'Descripción H', '901-234-5678');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (9, 1009, 'Avenida Central 678', '10:00:00', '19:00:00', 'Tienda I', 7, 'Ciudad I', 'País I', '2023-03-25 11:45:00', 'Descripción I', '291-334-5657');

INSERT INTO Locales (numLocal, idLocal, direccion, apertura, cierre, nombre_fanasioso, cant_empleados, ciudad, pais, fecha_apertura, descripcio, telefono)
VALUES (10, 1010, 'Avenida Secundaria 567', '09:30:00', '18:30:00', 'Tienda J', 13, 'Ciudad J', 'País J', '2024-04-15 08:00:00', 'Descripción J', '567-890-1234');

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (1, 1001, 10, 1);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (2, 1002, 9, 2);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (3, 1003, 8, 3);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (4, 1004, 7, 4);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (5, 1005, 6, 5);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (6, 1006, 5, 6);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (7, 1007, 4, 7);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (8, 1008, 3, 8);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (9, 1009, 2, 9);

INSERT INTO Gerente (numGerente, idGerente, Empleado, Local_numLocal)
VALUES (10, 1010, 1, 10);

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (1, 2.5, 'Harina', 'ID001', 1, 1);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (2, 1.8, 'Azúcar', 'ID002', 2, 2);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (3, 0.5, 'Sal', 'ID003', 3, 3);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (4, 3.2, 'Levadura', 'ID004', 4, 4);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (5, 1.0, 'Aceite', 'ID005', 5, 5);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (6, 0.7, 'Huevo', 'ID006', 6, 6);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (7, 2.3, 'Leche', 'ID007', 7, 7);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (8, 1.5, 'Mantequilla', 'ID008', 8, 8);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (9, 0.9, 'Chocolate', 'ID009', 9, 9);

INSERT INTO Ingredientes (Num_ingrediente, Cantidad_kg, Nombre, idIngrediente, Pedido, Producto)
VALUES (10, 2.1, 'Vainilla', 'ID010', 10, 10);

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (1, 500.00, 1200.00, '2024-01-15', 'FAC001', 1);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (2, 700.00, 1500.00, '2024-02-10', 'FAC002', 2);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (3, 600.00, 1300.00, '2024-03-05', 'FAC003', 3);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (4, 800.00, 1800.00, '2024-04-20', 'FAC004', 4);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (5, 400.00, 1100.00, '2024-05-01', 'FAC005', 5);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (6, 900.00, 2000.00, '2024-06-12', 'FAC006', 6);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (7, 750.00, 1600.00, '2024-07-25', 'FAC007', 7);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (8, 550.00, 1400.00, '2024-08-18', 'FAC008', 8);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (9, 650.00, 1700.00, '2024-09-09', 'FAC009', 9);

INSERT INTO Facturas_local (numFactura, Gastos, Ingresos, fechaFactura, id_factura, Local_numLocal)
VALUES (10, 700.00, 1900.00, '2024-10-30', 'FAC010', 10);

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (1, 'LIC001', 'Licencia médica', '2024-01-05', 'Licencia por enfermedad', '2024-01-10', '2024-01-15', 'Enfermedad', 'LICCOL001', 1);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (2, 'LIC002', 'Licencia personal', '2024-02-10', 'Licencia por asuntos personales', '2024-02-15', '2024-02-17', 'Asuntos personales', 'LICCOL002', 2);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (3, 'LIC003', 'Licencia médica', '2024-03-08', 'Licencia por enfermedad', '2024-03-10', '2024-03-12', 'Enfermedad', 'LICCOL003', 3);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (4, 'LIC004', 'Licencia de maternidad', '2024-04-20', 'Licencia por maternidad', '2024-04-25', '2024-07-31', 'Maternidad', 'LICCOL004', 4);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (5, 'LIC005', 'Licencia personal', '2024-05-12', 'Licencia por asuntos personales', '2024-05-15', '2024-05-16', 'Asuntos personales', 'LICCOL005', 5);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (6, 'LIC006', 'Licencia médica', '2024-06-18', 'Licencia por enfermedad', '2024-06-20', '2024-06-22', 'Enfermedad', 'LICCOL006', 6);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (7, 'LIC007', 'Licencia personal', '2024-07-25', 'Licencia por asuntos personales', '2024-07-28', '2024-07-29', 'Asuntos personales', 'LICCOL007', 7);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (8, 'LIC008', 'Licencia médica', '2024-08-10', 'Licencia por enfermedad', '2024-08-15', '2024-08-20', 'Enfermedad', 'LICCOL008', 8);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (9, 'LIC009', 'Licencia de paternidad', '2024-09-05', 'Licencia por paternidad', '2024-09-10', '2024-09-17', 'Paternidad', 'LICCOL009', 9);

INSERT INTO Licensias (numLicensias, idLicensias, Tipolicensia, duracion, descripcion, fechaInicio, fechaFinal, razon, Licensiascol, Empleado)
VALUES (10, 'LIC010', 'Licencia personal', '2024-10-20', 'Licencia por asuntos personales', '2024-10-25', '2024-10-27', 'Asuntos personales', 'LICCOL010', 10);

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (1, 1001, 20, 0, 1, 1);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (2, 1002, 18, 1, 2, 2);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (3, 1003, 22, 0, 3, 3);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (4, 1004, 20, 0, 4, 4);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (5, 1005, 21, 0, 5, 5);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (6, 1006, 19, 1, 6, 6);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (7, 1007, 17, 2, 7, 7);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (8, 1008, 23, 0, 8, 8);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (9, 1009, 20, 0, 9, 9);

INSERT INTO Presentismo (NumPresentismo, idPresentismo, asistencias, suspenciones, Licensias, Empleado)
VALUES (10, 1010, 16, 3, 10, 10);

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (1, 2001, 2, 1, 'Enfermedad', 'Baja', 1);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (2, 2002, 3, 0, 'Asuntos personales', 'Media', 2);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (3, 2003, 1, 2, 'Emergencia familiar', 'Alta', 3);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (4, 2004, 0, 1, 'Enfermedad', 'Baja', 4);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (5, 2005, 2, 0, 'Asuntos personales', 'Media', 5);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (6, 2006, 1, 2, 'Emergencia familiar', 'Alta', 6);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (7, 2007, 0, 1, 'Enfermedad', 'Baja', 7);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (8, 2008, 3, 0, 'Asuntos personales', 'Media', 8);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (9, 2009, 1, 2, 'Emergencia familiar', 'Alta', 9);

INSERT INTO Faltas (numFaltas, idFaltas, faltas, llegadas_tarde, razonFalta, gravedad, Empleado)
VALUES (10, 2010, 0, 1, 'Enfermedad', 'Baja', 10);

--------------------------------------------------------------------------------------------------------------------

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (1, 3001, 'Excavadora', 'Caterpillar', 'E320', 'Amarillo', 15000.0, 'Excavadora de gran capacidad', '2024-01-01', '2023-12-15', 'Maquinaria 1', 1, 1);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (2, 3002, 'Grúa', 'Liebherr', 'LTM 11200-9.1', 'Blanco', 50000.0, 'Grúa telescópica de alta capacidad', '2024-03-01', '2024-02-15', 'Maquinaria 2', 2, 2);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (3, 3003, 'Excavadora', 'Komatsu', 'PC200-8', 'Amarillo', 12000.0, 'Excavadora de tamaño mediano', '2024-02-01', '2024-01-15', 'Maquinaria 3', 3, 3);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (4, 3004, 'Bulldozer', 'Caterpillar', 'D6', 'Amarillo', 25000.0, 'Bulldozer para movimiento de tierra', '2024-04-01', '2024-03-15', 'Maquinaria 4', 4, 1);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (5, 3005, 'Grúa', 'Tadano', 'ATF 220G-5', 'Rojo', 45000.0, 'Grúa móvil todo terreno', '2024-03-01', '2024-02-15', 'Maquinaria 5', 5, 2);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (6, 3006, 'Excavadora', 'Hitachi', 'ZX350LC-6', 'Amarillo', 14000.0, 'Excavadora para excavación y carga', '2024-02-01', '2024-01-15', 'Maquinaria 6', 6, 3);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (7, 3007, 'Grúa', 'Kato', 'CR-130Rf', 'Amarillo', 32000.0, 'Grúa sobre orugas de alta capacidad', '2024-04-01', '2024-03-15', 'Maquinaria 7', 7, 1);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (8, 3008, 'Excavadora', 'Volvo', 'EC220DL', 'Amarillo', 13000.0, 'Excavadora de tamaño mediano', '2024-03-01', '2024-02-15', 'Maquinaria 8', 8, 2);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (9, 3009, 'Montacargas', 'Toyota', '8FGCU25', 'Azul', 4000.0, 'Montacargas de gas', '2024-02-01', '2024-01-15', 'Maquinaria 9', 9, 3);

INSERT INTO Maquinaria (numMaquinaria, idMaquinaria, tipoMaquina, Marca, Modelo, Color, Peso_kg, Descripcion, Garantia, ultimo_Mantenimiento, Maquinariacol, Local_numLocal, Provedor)
VALUES (10, 3010, 'Excavadora', 'JCB', 'JS130LC', 'Amarillo', 14000.0, 'Excavadora para excavación y carga', '2024-04-01', '2024-03-15', 'Maquinaria 10', 10, 1);

