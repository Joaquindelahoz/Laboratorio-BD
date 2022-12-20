//
//  main.cpp
//  Lab 4 Bases de Datos
//
//  Created by Joaquin De la Hoz Perez- Traverso on 20/12/22.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // ejericio 1//
    CREATE TABLE Municipio
    (
      Latitud INT NOT NULL,
      Longitud INT NOT NULL,
      Abreviatura INT NOT NULL,
      CodMunicipio INT NOT NULL,
      PRIMARY KEY (CodMunicipio)
    );

    CREATE TABLE Persona
    (
      NIF INT NOT NULL,
      Nacionalidad INT NOT NULL,
      FechaNac. INT NOT NULL,
      Nombre INT NOT NULL,
      Apellido_1 INT NOT NULL,
      Apellido_2 INT NOT NULL,
      Sexo INT NOT NULL,
      CodMunicipio INT NOT NULL,
      CodCatastro INT NOT NULL,
      Ser_cabeza_familia_NIF INT NOT NULL,
      PRIMARY KEY (NIF),
      FOREIGN KEY (CodMunicipio) REFERENCES Municipio(CodMunicipio),
      FOREIGN KEY (CodCatastro) REFERENCES Vivienda(CodCatastro),
      FOREIGN KEY (Ser_cabeza_familia_NIF) REFERENCES Persona(NIF)
    );

    CREATE TABLE Vivienda
    (
      CodRegistral VARCHAR NOT NULL,
      Orientación VARCHAR NOT NULL,
      CodPostal INT NOT NULL,
      Letra VARCHAR NOT NULL,
      Altura INT NOT NULL,
      calle VARCHAR NOT NULL,
      Nº INT NOT NULL,
      Portal INT NOT NULL,
      Nº_hab INT NOT NULL,
      Superficie INT NOT NULL,
      CodCatastro INT NOT NULL,
      NIF INT NOT NULL,
      PRIMARY KEY (CodCatastro),
      FOREIGN KEY (NIF) REFERENCES Persona(NIF)
    );
    //ejericio 2//
    CREATE TABLE Profesor
    (
      ID-P INT NOT NULL,
      NIF-P INT NOT NULL,
      Nombre INT NOT NULL,
      Especialidad INT NOT NULL,
      TLf INT NOT NULL,
      PRIMARY KEY (NIF-P)
    );

    CREATE TABLE Asignatura
    (
      Codigo-Asignatura INT NOT NULL,
      Nombre INT NOT NULL,
      NIF-P INT NOT NULL,
      PRIMARY KEY (Codigo-Asignatura),
      FOREIGN KEY (NIF-P) REFERENCES Profesor(NIF-P)
    );

    CREATE TABLE Alumno
    (
      Num-Matrciula INT NOT NULL,
      Nombre VARCHAR NOT NULL,
      fecha_nac DATE NOT NULL,
      Tlf INT NOT NULL,
      Codigo-Asignatura INT NOT NULL,
      PRIMARY KEY (Num-Matrciula),
      FOREIGN KEY (Codigo-Asignatura) REFERENCES Asignatura(Codigo-Asignatura)
    );
    
    //ejericio 3//
    CREATE TABLE Región
    (
      Nombre_de_Región VARCHAR NOT NULL,
      PRIMARY KEY (Nombre_de_Región)
    );

    CREATE TABLE Localidad
    (
      Codigo_de_localidad INT NOT NULL,
      Nombre_Localidad INT NOT NULL,
      PRIMARY KEY (Codigo_de_localidad)
    );

    CREATE TABLE Empleado
    (
      ID_E INT NOT NULL,
      DNI_E INT NOT NULL,
      Nombre INT NOT NULL,
      (Apellidos) INT NOT NULL,
      Teléfono INT NOT NULL,
      Salario INT NOT NULL,
      Codigo_de_localidad INT NOT NULL,
      PRIMARY KEY (ID_E),
      FOREIGN KEY (Codigo_de_localidad) REFERENCES Localidad(Codigo_de_localidad)
    );

    CREATE TABLE Provincia
    (
      Codigo_Provincial INT NOT NULL,
      Nombre_Provincia INT NOT NULL,
      Nombre_de_Región VARCHAR NOT NULL,
      Codigo_de_localidad INT NOT NULL,
      PRIMARY KEY (Codigo_Provincial),
      FOREIGN KEY (Nombre_de_Región) REFERENCES Región(Nombre_de_Región),
      FOREIGN KEY (Codigo_de_localidad) REFERENCES Localidad(Codigo_de_localidad)
    );
    //ejercicio 4//
    CREATE TABLE Departamento
    (
      Código_D VARCHAR NOT NULL,
      Localización VARCHAR NOT NULL,
      PRIMARY KEY (Código_D)
    );

    CREATE TABLE Empleado
    (
      id_e INT NOT NULL,
      DNI_E INT NOT NULL,
      Teléfono INT NOT NULL,
      Salario INT NOT NULL,
      Código_D VARCHAR NOT NULL,
      ser_jefe_id_e INT NOT NULL,
      PRIMARY KEY (id_e),
      FOREIGN KEY (Código_D) REFERENCES Departamento(Código_D),
      FOREIGN KEY (ser_jefe_id_e) REFERENCES Empleado(id_e)
    );
    //ejericio 5//
    CREATE TABLE Equipo
    (
      Codigo INT NOT NULL,
      PRIMARY KEY (Codigo)
    );

    CREATE TABLE Instalador
    (
      NIF INT NOT NULL,
      Nombre INT NOT NULL,
      Dirección_ INT NOT NULL,
      Tlf INT NOT NULL,
      N_inst INT NOT NULL,
      PRIMARY KEY (NIF)
    );

    CREATE TABLE Cliente
    (
      NIF INT NOT NULL,
      Nombre INT NOT NULL,
      Dirección INT NOT NULL,
      tlf INT NOT NULL,
      PRIMARY KEY (NIF)
    );

    CREATE TABLE Compra
    (
      Fecha_compra INT NOT NULL,
      Codigo INT NOT NULL,
      NIF INT NOT NULL,
      PRIMARY KEY (Codigo, NIF),
      FOREIGN KEY (Codigo) REFERENCES Equipo(Codigo),
      FOREIGN KEY (NIF) REFERENCES Cliente(NIF)
    );
    //ejericio 6//
    CREATE TABLE Empleados
    (
      Datos_personales INT NOT NULL,
      DNI INT NOT NULL,
      Tlf INT NOT NULL,
      PRIMARY KEY (DNI)
    );

    CREATE TABLE Periodistas
    (
      Datos_personales INT NOT NULL,
      Dni INT NOT NULL,
      tlf INT NOT NULL,
      especialidad INT NOT NULL,
      PRIMARY KEY (Dni)
    );

    CREATE TABLE Sucursales
    (
      Domicilio INT NOT NULL,
      tlf INT NOT NULL,
      CodSucursal INT NOT NULL,
      DNI INT NOT NULL,
      PRIMARY KEY (CodSucursal),
      FOREIGN KEY (DNI) REFERENCES Empleados(DNI)
    );

    CREATE TABLE Revistas
    (
      Fecha DATE NOT NULL,
      Nºejemplares INT NOT NULL,
      Nºpaginas INT NOT NULL,
      Periodicidad VARCHAR NOT NULL,
      Titulo VARCHAR NOT NULL,
      Nºregistro INT NOT NULL,
      CodSucursal INT NOT NULL,
      PRIMARY KEY (Nºregistro),
      FOREIGN KEY (CodSucursal) REFERENCES Sucursales(CodSucursal)
    );

    CREATE TABLE Escriben
    (
      Nºregistro INT NOT NULL,
      Dni INT NOT NULL,
      PRIMARY KEY (Nºregistro, Dni),
      FOREIGN KEY (Nºregistro) REFERENCES Revistas(Nºregistro),
      FOREIGN KEY (Dni) REFERENCES Periodistas(Dni)
    );
    //ejericio 7//
    CREATE TABLE proveedores
    (
      codigo VARCHAR NOT NULL,
      nombre VARCHAR NOT NULL,
      direccion VARCHAR NOT NULL,
      tlf INT NOT NULL,
      web VARCHAR NOT NULL,
      PRIMARY KEY (codigo)
    );

    CREATE TABLE Cliente
    (
      codigo VARCHAR NOT NULL,
      nombre VARCHAR NOT NULL,
      ciudad VARCHAR NOT NULL,
      calle VARCHAR NOT NULL,
      nº INT NOT NULL,
      Tlf INT NOT NULL,
      PRIMARY KEY (codigo)
    );

    CREATE TABLE ventas
    (
      id VARCHAR NOT NULL,
      fecha DATE NOT NULL,
      cliente VARCHAR NOT NULL,
      descuento VARCHAR NOT NULL,
      monto VARCHAR NOT NULL,
      codigo VARCHAR NOT NULL,
      PRIMARY KEY (id),
      FOREIGN KEY (codigo) REFERENCES Cliente(codigo)
    );

    CREATE TABLE categoria
    (
      id INT NOT NULL,
      nombre VARCHAR NOT NULL,
      descripcion VARCHAR NOT NULL,
      PRIMARY KEY (id)
    );

    CREATE TABLE productos
    (
      nombre_proveedor VARCHAR NOT NULL,
      precio_actual INT NOT NULL,
      stock VARCHAR NOT NULL,
      id VARCHAR NOT NULL,
      nombre VARCHAR NOT NULL,
      codigo VARCHAR NOT NULL,
      id INT NOT NULL,
      PRIMARY KEY (id),
      FOREIGN KEY (codigo) REFERENCES proveedores(codigo),
      FOREIGN KEY (id) REFERENCES categoria(id)
    );

    CREATE TABLE participa
    (
      id VARCHAR NOT NULL,
      id VARCHAR NOT NULL,
      PRIMARY KEY (id, id),
      FOREIGN KEY (id) REFERENCES ventas(id),
      FOREIGN KEY (id) REFERENCES productos(id)
    );
    //ejericio 8//
    CREATE TABLE Curso
    (
      Código_de_curso VARCHAR NOT NULL,
      Denominacion VARCHAR NOT NULL,
      Descripción VARCHAR NOT NULL,
      Nº_horas INT NOT NULL,
      Coste INT NOT NULL,
      PRIMARY KEY (Código_de_curso)
    );

    CREATE TABLE Prerrequisito
    (
      CodPre VARCHAR NOT NULL,
      Código_de_curso VARCHAR,
      PRIMARY KEY (CodPre),
      FOREIGN KEY (Código_de_curso) REFERENCES Curso(Código_de_curso)
    );

    CREATE TABLE Profesor
    (
      NIF VARCHAR NOT NULL,
      Fecha_Nacimiento DATE NOT NULL,
      Nacionalidad VARCHAR NOT NULL,
      Sexo VARCHAR NOT NULL,
      Nº_de_hijos INT NOT NULL,
      Salario INT NOT NULL,
      Acreditación VARCHAR NOT NULL,
      PRIMARY KEY (NIF)
    );

    CREATE TABLE Alumnos
    (
      NIF INT NOT NULL,
      Código_de_curso VARCHAR NOT NULL,
      PRIMARY KEY (NIF),
      FOREIGN KEY (Código_de_curso) REFERENCES Curso(Código_de_curso)
    );

    CREATE TABLE Recomendación
    (
      CodPre VARCHAR NOT NULL,
      PRIMARY KEY (CodPre),
      FOREIGN KEY (CodPre) REFERENCES Prerrequisito(CodPre)
    );

    CREATE TABLE Obligatorio
    (
      CodPre VARCHAR NOT NULL,
      PRIMARY KEY (CodPre),
      FOREIGN KEY (CodPre) REFERENCES Prerrequisito(CodPre)
    );

    CREATE TABLE Edición
    (
      Código_de_Curso VARCHAR NOT NULL,
      Lugar VARCHAR NOT NULL,
      Fecha DATE NOT NULL,
      Formato VARCHAR NOT NULL,
      Horario INT NOT NULL,
      Numero_de_horas INT NOT NULL,
      Código_de_curso VARCHAR NOT NULL,
      PRIMARY KEY (Código_de_curso),
      FOREIGN KEY (Código_de_curso) REFERENCES Curso(Código_de_curso),
      UNIQUE (Código_de_Curso)
    );

    CREATE TABLE Imparte
    (
      Código_de_curso VARCHAR NOT NULL,
      NIF VARCHAR NOT NULL,
      PRIMARY KEY (Código_de_curso, NIF),
      FOREIGN KEY (Código_de_curso) REFERENCES Curso(Código_de_curso),
      FOREIGN KEY (NIF) REFERENCES Profesor(NIF)
    );
    //ejericio 9//
    CREATE TABLE Motorizaciones
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor)
    );

    CREATE TABLE Hibrido
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motorizaciones(CodMotor)
    );

    CREATE TABLE Hidrogeno
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motorizaciones(CodMotor)
    );

    CREATE TABLE Diesel
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motorizaciones(CodMotor)
    );

    CREATE TABLE Gasolina
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motorizaciones(CodMotor)
    );

    CREATE TABLE Electrico
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motorizaciones(CodMotor)
    );
    // ejericio 10//
    CREATE TABLE Aeroterrestre
    (
      CodAeroterrestre INT NOT NULL,
      PRIMARY KEY (CodAeroterrestre)
    );

    CREATE TABLE Medios_de_Transporte
    (
      CodTransporte VARCHAR NOT NULL,
      CodMediosTransporte VARCHAR NOT NULL,
      PRIMARY KEY (CodTransporte),
      UNIQUE (CodMediosTransporte)
    );

    CREATE TABLE Aereo
    (
      CodAereo VARCHAR NOT NULL,
      CodTransporte VARCHAR NOT NULL,
      PRIMARY KEY (CodTransporte),
      FOREIGN KEY (CodTransporte) REFERENCES Medios_de_Transporte(CodTransporte),
      UNIQUE (CodAereo)
    );

    CREATE TABLE Acuatico
    (
      CodAcuatico VARCHAR NOT NULL,
      CodTransporte VARCHAR NOT NULL,
      PRIMARY KEY (CodTransporte),
      FOREIGN KEY (CodTransporte) REFERENCES Medios_de_Transporte(CodTransporte),
      UNIQUE (CodAcuatico)
    );

    CREATE TABLE Anfibio
    (
      CodAnfibio VARCHAR NOT NULL,
      PRIMARY KEY (CodAnfibio)
    );

    CREATE TABLE Terrestre
    (
      CodTerrestre VARCHAR NOT NULL,
      CodTransporte VARCHAR NOT NULL,
      PRIMARY KEY (CodTransporte),
      FOREIGN KEY (CodTransporte) REFERENCES Medios_de_Transporte(CodTransporte),
      UNIQUE (CodTerrestre)
    );

    CREATE TABLE pertenece
    (
      CodAeroterrestre INT NOT NULL,
      CodTransporte VARCHAR NOT NULL,
      PRIMARY KEY (CodAeroterrestre, CodTransporte),
      FOREIGN KEY (CodAeroterrestre) REFERENCES Aeroterrestre(CodAeroterrestre),
      FOREIGN KEY (CodTransporte) REFERENCES Terrestre(CodTransporte)
    );

    CREATE TABLE pertenece
    (
      CodTransporte VARCHAR NOT NULL,
      CodAnfibio VARCHAR NOT NULL,
      PRIMARY KEY (CodTransporte, CodAnfibio),
      FOREIGN KEY (CodTransporte) REFERENCES Acuatico(CodTransporte),
      FOREIGN KEY (CodAnfibio) REFERENCES Anfibio(CodAnfibio)
    );

    CREATE TABLE pertenece
    (
      CodAeroterrestre INT NOT NULL,
      CodTransporte VARCHAR NOT NULL,
      PRIMARY KEY (CodAeroterrestre, CodTransporte),
      FOREIGN KEY (CodAeroterrestre) REFERENCES Aeroterrestre(CodAeroterrestre),
      FOREIGN KEY (CodTransporte) REFERENCES Aereo(CodTransporte)
    );
    //ejericio 11//
    CREATE TABLE Documentos_Administrativos
    (
      Código_Documentos.A VARCHAR NOT NULL,
      PRIMARY KEY (Código_Documentos.A)
    );

    CREATE TABLE Pago
    (
      Código_Pago VARCHAR NOT NULL,
      Importe INT NOT NULL,
      PRIMARY KEY (Código_Pago)
    );

    CREATE TABLE Grado
    (
      Código_de_Grado INT NOT NULL,
      PRIMARY KEY (Código_de_Grado)
    );

    CREATE TABLE Curso
    (
      CodCurso VARCHAR NOT NULL,
      Código_de_Grado INT NOT NULL,
      PRIMARY KEY (CodCurso),
      FOREIGN KEY (Código_de_Grado) REFERENCES Grado(Código_de_Grado)
    );

    CREATE TABLE Matrícula
    (
      Codigo_de_matrícula VARCHAR NOT NULL,
      Código_Pago VARCHAR NOT NULL,
      CodCurso VARCHAR NOT NULL,
      PRIMARY KEY (Codigo_de_matrícula),
      FOREIGN KEY (Código_Pago) REFERENCES Pago(Código_Pago),
      FOREIGN KEY (CodCurso) REFERENCES Curso(CodCurso)
    );

    CREATE TABLE Alumno
    (
      NIF VARCHAR NOT NULL,
      Código_Documentos.A VARCHAR NOT NULL,
      Codigo_de_matrícula VARCHAR NOT NULL,
      PRIMARY KEY (NIF),
      FOREIGN KEY (Código_Documentos.A) REFERENCES Documentos_Administrativos(Código_Documentos.A),
      FOREIGN KEY (Codigo_de_matrícula) REFERENCES Matrícula(Codigo_de_matrícula)
    );

    CREATE TABLE Tarjeta_Identidad
    (
      Codigo_Tarjeta VARCHAR NOT NULL,
      NIF VARCHAR NOT NULL,
      PRIMARY KEY (Codigo_Tarjeta),
      FOREIGN KEY (NIF) REFERENCES Alumno(NIF)
    );
    //ejericio 12//
    CREATE TABLE Criptomoneda
    (
      Codigo_Criptomoneda INT NOT NULL,
      PRIMARY KEY (Codigo_Criptomoneda)
    );

    CREATE TABLE Registro
    (
      CodRegistro INT NOT NULL,
      PRIMARY KEY (CodRegistro)
    );

    CREATE TABLE Algoritmo
    (
      Código_Algoritmo VARCHAR NOT NULL,
      Codigo_Criptomoneda INT NOT NULL,
      PRIMARY KEY (Código_Algoritmo),
      FOREIGN KEY (Codigo_Criptomoneda) REFERENCES Criptomoneda(Codigo_Criptomoneda)
    );

    CREATE TABLE Wallet
    (
      Clave_Pública VARCHAR NOT NULL,
      Clave_Privada VARCHAR NOT NULL,
      CodRegistro INT NOT NULL,
      PRIMARY KEY (Clave_Pública),
      FOREIGN KEY (CodRegistro) REFERENCES Registro(CodRegistro)
    );

    CREATE TABLE Propietario
    (
      Clave_Pública VARCHAR NOT NULL,
      Codigo_Criptomoneda INT NOT NULL,
      PRIMARY KEY (Clave_Pública),
      FOREIGN KEY (Clave_Pública) REFERENCES Wallet(Clave_Pública),
      FOREIGN KEY (Codigo_Criptomoneda) REFERENCES Criptomoneda(Codigo_Criptomoneda)
    );

    CREATE TABLE Usuario
    (
      Clave_Pública VARCHAR NOT NULL,
      CodRegistro INT NOT NULL,
      PRIMARY KEY (Clave_Pública),
      FOREIGN KEY (Clave_Pública) REFERENCES Wallet(Clave_Pública),
      FOREIGN KEY (CodRegistro) REFERENCES Registro(CodRegistro)
    );

    CREATE TABLE Transacciones_Digitales
    (
      CodTransaccion INT NOT NULL,
      Código_Algoritmo VARCHAR NOT NULL,
      PRIMARY KEY (CodTransaccion),
      FOREIGN KEY (Código_Algoritmo) REFERENCES Algoritmo(Código_Algoritmo)
    );

    CREATE TABLE Ingresos
    (
      CodTransaccion INT NOT NULL,
      PRIMARY KEY (CodTransaccion),
      FOREIGN KEY (CodTransaccion) REFERENCES Transacciones_Digitales(CodTransaccion)
    );

    CREATE TABLE Intercambios
    (
      CodTransaccion INT NOT NULL,
      PRIMARY KEY (CodTransaccion),
      FOREIGN KEY (CodTransaccion) REFERENCES Transacciones_Digitales(CodTransaccion)
    );

    CREATE TABLE Pagos
    (
      CodTransaccion INT NOT NULL,
      PRIMARY KEY (CodTransaccion),
      FOREIGN KEY (CodTransaccion) REFERENCES Transacciones_Digitales(CodTransaccion)
    );
    //ejericiio 13//
    CREATE TABLE Motor
    (
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor)
    );

    CREATE TABLE Híbrido
    (
      Consumo VARCHAR NOT NULL,
      Autonomía VARCHAR NOT NULL,
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motor(CodMotor)
    );

    CREATE TABLE Térmico
    (
      Consumo VARCHAR NOT NULL,
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motor(CodMotor)
    );

    CREATE TABLE Eléctrico
    (
      Autonomia VARCHAR NOT NULL,
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodMotor),
      FOREIGN KEY (CodMotor) REFERENCES Motor(CodMotor)
    );

    CREATE TABLE Fabricante
    (
      CodFabri VARCHAR NOT NULL,
      PRIMARY KEY (CodFabri)
    );

    CREATE TABLE Escudería
    (
      CodEscu INT NOT NULL,
      PRIMARY KEY (CodEscu)
    );

    CREATE TABLE Fabricar
    (
      CodFabri VARCHAR NOT NULL,
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodFabri, CodMotor),
      FOREIGN KEY (CodFabri) REFERENCES Fabricante(CodFabri),
      FOREIGN KEY (CodMotor) REFERENCES Motor(CodMotor)
    );

    CREATE TABLE Coche
    (
      CodCoche VARCHAR NOT NULL,
      CodEscu INT NOT NULL,
      CodMotor VARCHAR NOT NULL,
      PRIMARY KEY (CodCoche),
      FOREIGN KEY (CodEscu) REFERENCES Escudería(CodEscu),
      FOREIGN KEY (CodMotor) REFERENCES Motor(CodMotor)
    );

    CREATE TABLE Fabricar
    (
      CodFabri VARCHAR NOT NULL,
      CodCoche VARCHAR NOT NULL,
      PRIMARY KEY (CodFabri, CodCoche),
      FOREIGN KEY (CodFabri) REFERENCES Fabricante(CodFabri),
      FOREIGN KEY (CodCoche) REFERENCES Coche(CodCoche)
    );
    //ejericio 14//
    CREATE TABLE Cursos
    (
      Cod_curso INT NOT NULL,
      denominación VARCHAR NOT NULL,
      nº_de_horas INT NOT NULL,
      Coste INT NOT NULL,
      Cursos_previos INT,
      PRIMARY KEY (Cod_curso)
    );

    CREATE TABLE Ediciones
    (
      Lugar VARCHAR NOT NULL,
      Fecha_inicio DATE NOT NULL,
      Formato VARCHAR NOT NULL,
      Horarios INT NOT NULL,
      Nº_de_horas INT NOT NULL,
      Cod_curso INT NOT NULL,
      PRIMARY KEY (Fecha_inicio),
      FOREIGN KEY (Cod_curso) REFERENCES Cursos(Cod_curso)
    );

    CREATE TABLE Profesores
    (
      NIF VARCHAR NOT NULL,
      Fecha_nacimiento DATE NOT NULL,
      Nacionalidad VARCHAR NOT NULL,
      Sexo VARCHAR NOT NULL,
      Nº_hijos INT NOT NULL,
      Salario INT NOT NULL,
      Acreditación VARCHAR NOT NULL,
      Alumno INT NOT NULL,
      PRIMARY KEY (NIF)
    );

    CREATE TABLE Imparten
    (
      Cod_curso INT NOT NULL,
      NIF VARCHAR NOT NULL,
      PRIMARY KEY (Cod_curso, NIF),
      FOREIGN KEY (Cod_curso) REFERENCES Cursos(Cod_curso),
      FOREIGN KEY (NIF) REFERENCES Profesores(NIF)
    );
    //ejericio 15//
    
    CREATE TABLE Raciales
    (
      Etnias_enfrentadas INT NOT NULL,
      Cod_conflicto INT NOT NULL,
      PRIMARY KEY (Cod_conflicto),
      FOREIGN KEY (Cod_conflicto) REFERENCES Conflicto_(Cod_conflicto),
      UNIQUE (Etnias_enfrentadas)
    );

    CREATE TABLE Territoriales
    (
      Numero_regiones_afectadas INT NOT NULL,
      Cod_conflicto INT NOT NULL,
      PRIMARY KEY (Cod_conflicto),
      FOREIGN KEY (Cod_conflicto) REFERENCES Conflicto_(Cod_conflicto),
      UNIQUE (Numero_regiones_afectadas)
    );

    CREATE TABLE Grupos_armados
    (
      Fecha_incorporación DATE NOT NULL,
      Fecha_salida DATE NOT NULL,
      Código_armado INT NOT NULL,
      Nombre VARCHAR NOT NULL,
      PRIMARY KEY (Código_armado)
    );

    CREATE TABLE Organizaciones_mediadoras
    (
      Fecha_incorporación DATE NOT NULL,
      Fecha_salida DATE NOT NULL,
      Nombre VARCHAR NOT NULL,
      Gubernamental VARCHAR NOT NULL,
      No_gubernamental_ VARCHAR NOT NULL,
      internacional VARCHAR NOT NULL,
      Personas_desplegadas INT NOT NULL,
      Medica VARCHAR NOT NULL,
      Diplomatica VARCHAR NOT NULL,
      Presencial VARCHAR NOT NULL,
      Dialoga VARCHAR NOT NULL,
      Cod_conflicto INT NOT NULL,
      PRIMARY KEY (Fecha_salida),
      FOREIGN KEY (Cod_conflicto) REFERENCES Conflicto_(Cod_conflicto)
    );

    CREATE TABLE División
    (
      Barcos INT NOT NULL,
      Hombres INT NOT NULL,
      Aviones INT NOT NULL,
      Tanques INT NOT NULL,
      Bajas INT NOT NULL,
      Código_armado INT NOT NULL,
      PRIMARY KEY (Barcos, Hombres, Aviones, Tanques, Bajas),
      FOREIGN KEY (Código_armado) REFERENCES Grupos_armados(Código_armado)
    );

    CREATE TABLE Lider_político
    (
      Nombre VARCHAR NOT NULL,
      Cod_grupo_armado INT NOT NULL,
      Apoyos INT NOT NULL,
      Diaolga VARCHAR NOT NULL,
      Código_armado INT NOT NULL,
      PRIMARY KEY (Cod_grupo_armado),
      FOREIGN KEY (Código_armado) REFERENCES Grupos_armados(Código_armado)
    );

    CREATE TABLE Traficantes_de_armas
    (
      Nombre INT NOT NULL,
      Número_de_sumistro INT NOT NULL,
      PRIMARY KEY (Nombre)
    );

    CREATE TABLE Jefes_militares
    (
      Cod_militar INT NOT NULL,
      rango INT NOT NULL,
      Nombre_Jefe VARCHAR NOT NULL,
      Barcos INT NOT NULL,
      Hombres INT NOT NULL,
      Aviones INT NOT NULL,
      Tanques INT NOT NULL,
      Bajas INT NOT NULL,
      Cod_grupo_armado INT NOT NULL,
      PRIMARY KEY (Cod_militar),
      FOREIGN KEY (Barcos, Hombres, Aviones, Tanques, Bajas) REFERENCES División(Barcos, Hombres, Aviones, Tanques, Bajas),
      FOREIGN KEY (Cod_grupo_armado) REFERENCES Lider_político(Cod_grupo_armado)
    );

    CREATE TABLE Intervienen_
    (
      Cod_conflicto INT NOT NULL,
      Código_armado INT NOT NULL,
      PRIMARY KEY (Cod_conflicto, Código_armado),
      FOREIGN KEY (Cod_conflicto) REFERENCES Conflicto_(Cod_conflicto),
      FOREIGN KEY (Código_armado) REFERENCES Grupos_armados(Código_armado)
    );

    CREATE TABLE Dialoga
    (
      Cod_grupo_armado INT NOT NULL,
      Fecha_salida DATE NOT NULL,
      PRIMARY KEY (Cod_grupo_armado, Fecha_salida),
      FOREIGN KEY (Cod_grupo_armado) REFERENCES Lider_político(Cod_grupo_armado),
      FOREIGN KEY (Fecha_salida) REFERENCES Organizaciones_mediadoras(Fecha_salida)
    );

    CREATE TABLE _Armas
    (
      Nombre VARCHAR NOT NULL,
      Indicador_capacidad INT NOT NULL,
      Nombre INT NOT NULL,
      PRIMARY KEY (Indicador_capacidad),
      FOREIGN KEY (Nombre) REFERENCES Traficantes_de_armas(Nombre)
    );

    CREATE TABLE Suministran
    (
      Número_total INT NOT NULL,
      Indicador_capacidad INT NOT NULL,
      Código_armado INT NOT NULL,
      PRIMARY KEY (Indicador_capacidad, Código_armado),
      FOREIGN KEY (Indicador_capacidad) REFERENCES _Armas(Indicador_capacidad),
      FOREIGN KEY (Código_armado) REFERENCES Grupos_armados(Código_armado)
    );
    //ejericio 16//
    CREATE TABLE Banco
    (
      CodBanco INT NOT NULL,
      PRIMARY KEY (CodBanco)
    );

    CREATE TABLE Sucursales
    (
      Nombre INT NOT NULL,
      Ciudad INT NOT NULL,
      CodBanco INT NOT NULL,
      PRIMARY KEY (Nombre),
      FOREIGN KEY (CodBanco) REFERENCES Banco(CodBanco)
    );

    CREATE TABLE Activos
    (
      Nombre INT NOT NULL,
      CodBanco INT NOT NULL,
      FOREIGN KEY (Nombre) REFERENCES Sucursales(Nombre),
      FOREIGN KEY (CodBanco) REFERENCES Banco(CodBanco)
    );

    CREATE TABLE Empleados
    (
      Id_empleado INT NOT NULL,
      telefono INT NOT NULL,
      Nombre INT NOT NULL,
      Nombre INT NOT NULL,
      Id_empleado INT NOT NULL,
      Antigüedad_ INT NOT NULL,
      CodBanco INT NOT NULL,
      PRIMARY KEY (Id_empleado),
      FOREIGN KEY (CodBanco) REFERENCES Banco(CodBanco)
    );

    CREATE TABLE Cuentas
    (
      Número_de_cuenta INT NOT NULL,
      Saldo INT NOT NULL,
      Dia INT NOT NULL,
      Mes INT NOT NULL,
      Año INT NOT NULL,
      PRIMARY KEY (Número_de_cuenta),
      UNIQUE (Saldo)
    );

    CREATE TABLE Cuentas_corrientes
    (
      Interes INT NOT NULL,
      Número_de_cuenta INT NOT NULL,
      PRIMARY KEY (Número_de_cuenta),
      FOREIGN KEY (Número_de_cuenta) REFERENCES Cuentas(Número_de_cuenta)
    );

    CREATE TABLE Cuentas_ahorro
    (
      Descubierto INT NOT NULL,
      Número_de_cuenta INT NOT NULL,
      PRIMARY KEY (Número_de_cuenta),
      FOREIGN KEY (Número_de_cuenta) REFERENCES Cuentas(Número_de_cuenta)
    );

    CREATE TABLE Clientes
    (
      Id-Cliente INT NOT NULL,
      Nombre INT NOT NULL,
      Calle INT NOT NULL,
      Ciudad INT NOT NULL,
      CodBanco INT NOT NULL,
      PRIMARY KEY (Id-Cliente),
      FOREIGN KEY (CodBanco) REFERENCES Banco(CodBanco)
    );

    CREATE TABLE Prestamos
    (
      Numero INT NOT NULL,
      Importe INT NOT NULL,
      Número_de_pagos INT NOT NULL,
      Nombre INT NOT NULL,
      Id-Cliente INT NOT NULL,
      PRIMARY KEY (Numero),
      FOREIGN KEY (Nombre) REFERENCES Sucursales(Nombre),
      FOREIGN KEY (Id-Cliente) REFERENCES Clientes(Id-Cliente)
    );

    CREATE TABLE Pagos
    (
      Número_de_pago INT NOT NULL,
      Mes INT NOT NULL,
      Dia INT NOT NULL,
      Año INT NOT NULL,
      Importe INT NOT NULL,
      Numero INT NOT NULL,
      PRIMARY KEY (Número_de_pago),
      FOREIGN KEY (Numero) REFERENCES Prestamos(Numero)
    );

    CREATE TABLE Banquero_particular
    (
      CodBanquero INT NOT NULL,
      PRIMARY KEY (CodBanquero)
    );

    CREATE TABLE Responsable_de_prestamos
    (
      CodBanquero INT NOT NULL,
      PRIMARY KEY (CodBanquero),
      FOREIGN KEY (CodBanquero) REFERENCES Banquero_particular(CodBanquero)
    );

    CREATE TABLE Banquero_personal
    (
      CodBanquero INT NOT NULL,
      PRIMARY KEY (CodBanquero),
      FOREIGN KEY (CodBanquero) REFERENCES Banquero_particular(CodBanquero)
    );

    CREATE TABLE Asocian
    (
      Id-Cliente INT NOT NULL,
      Número_de_cuenta INT NOT NULL,
      PRIMARY KEY (Id-Cliente, Número_de_cuenta),
      FOREIGN KEY (Id-Cliente) REFERENCES Clientes(Id-Cliente),
      FOREIGN KEY (Número_de_cuenta) REFERENCES Cuentas(Número_de_cuenta)
    );
    /
    std::cout << "Hello, World!\n";
    return 0;
}
