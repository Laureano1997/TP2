# TPN2_Monitoreo_Electrónico_de_Invernadero
El presente repositorio contiene la idea de proyecto correspondiente a la materia Sistemas Embebidos (86.65) a desarrollar en el TP2 durante el primer cuatrimestre del 2025

## Título:
Monitoreo Electrónico de Invernadero

## Alumno:
Wawryczuk Laureano Agustin (102400)

## Objetivo: 
Realizar un sistema automatico para mantener un entorno controlado para plantas y monitorear su desarrollo.

## Desarrollo:
El sistema de monitoreo del invernadero deberá medir temperatura ambiente y humedad del suelo para mantener estos parámetros dentro de los requeridos por una planta específica. 
Apunta a plantas que requieren un cuidado especial y deberá ser autónomo, solo precisará la intervención del usuario ante agotamiento del agua dentro del reservorio. Ante esta eventualidad encenderá un LED indicando la ausencia de agua. Si el alerta es ignorado luego de una hora activará un Buzzer que podrá ser apagado con un pulsador de reset.
El sistema deberá activar un sistema de riego en caso de ser necesario, comparando contra los datos cargados para la planta específica en la base de datos.

La cantidad de agua en el tanque, la temperatura, y la humedad del suelo serán enviados via UART a la computadora cada una hora para poder realizar el monitoreo remoto y obtener estadísticas.

Se agregó a este sistema un display LCD de 16x2 que indicará el estado del tanque y la temperatura del recinto.

En caso de quedarse sin agua, el sistema encenderá un LED indicando que el sistema no tiene agua, sin embargo si luego de 1 hora no se recarga el agua en el tanque comenzará a sonar un buzzer, enviará un mensaje de alerta al display y otro a la computadora indicando que el sistema está bloqueado por falta de agua.

# Periféricos a utilizar:

-Sensor de Temperatura LM35

-Sensor de humedad del suelo anticorrosión 

-Electroválvula

-LED de alerta por falta de agua

-Buzzer
