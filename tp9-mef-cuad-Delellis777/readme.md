# Repositorio con programa ejemplo en C para PIC16F887 {#mainpage}
Para trabajar con el compilador XC8(v2.40) con MPLABX IDE v5.30

## Módulos ya disponibles
Nombre|Descripción
------|-----------
`uart`|Permite el manejo del puerto serie
`display`|Permite el manejo de un display de 7 segmentos
`tick`|Permite utilizar el contador de Tick para temporizaciones

Manual del PIC [PIC16F882/883/884/886/887 Data Sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/40001291H.pdf)

## Datos del alumno :nerd_face:
Completa con tus datos la siguiente tabla:

Campo|Detalle
------|-----------
Nombre| Nnnn
Apellido| Aaaa
Curso| 6°Electrónica
Año| 20XX

## Máquinas de Estado para Señales de Cuadratura
Las señales de cuadratura como las que provienen de un encoder incremental permiten detectar tanto la cantidad de pulsos o eventos que suceden así también como el sentido en el cual estos suceden.

![imagen](https://user-images.githubusercontent.com/64550311/127938049-29c1866e-dc69-4550-b17e-687c259ba566.png)

En la figura se  observa como según que señal aparece primero se puede determinar si hay que incrementar o decrementar la cuenta, trabajando con una resolución x1.

## Pautas del TP :man_teacher:
Los siguientes puntos se deben resolver en forma individual codificando en C para que los programas obtenidos corran en el Circuito con PIC para TP. Se debe bajar al microcontrolador el firmware obtenido al compilar y luego realizar físicamente las pruebas funcionales para verificar que cumpla con lo pedido en cada enunciado. También se debe entregar este repositorio en GitHub con la documentación de los diagramas solicitados.

# Enunciado del TPSE09: MEF para Señales de Cuadratura :gear::door:
Utilizando la herramienta [https://app.diagrams.net/](https://app.diagrams.net/) o Libreoffice Draw pata graficar los diagramas de estado

Codifica un programa que:
## 1. Contador de ingresos / regresos por sensores y señal de cuadratura :gear::1234::walking:
- [ ] Partiendo del template implementa y documenta en `punto1.pdf` la representación del diagrama de estados de una máquina de estado que:

***Recuerda:*** **Estado**(en negro:black_large_square:),  **condición**(en rojo:red_square:) **/ acción**(en azul:blue_square:)

- [ ] Suponiendo primero que se inicia con los dos sensores en 1
- [ ] Inicie con los leds verde:green_circle:, amarillo:yellow_circle: y rojo:red_circle: apagados y el display 7 segmentos en 0 utilizando la función `displayWrite`
- [ ] Detecte el sentido de circulación utilizando dos sensores conectados como la tecla 1:one: y la tecla 2:two: (con etiquetas `PIN_TEC1` y `PIN_TEC2` en el código)

![imagen](https://user-images.githubusercontent.com/64550311/127939344-37c505c3-6223-46d4-8dbc-40ae8890c3b6.png)

- [ ] Con cada ingreso (S1:one: antes que S2:two:) incremente en 1:+1: el numero en el display 7 segmentos (con rollover, volviendo a 0 si pasa de 9) y prenda solo el led verde:green_circle:
- [ ] Con cada egreso (S2:two: antes que S1:one:) decremente en 1:-1: el numero en el display 7 segmentos (con rollover, volviendo a 9 si baja de 0) y prenda solo el led amarillo:yellow_circle:
- [ ] Si hay alguna transición prohibida prenda el led rojo:red_circle: marcando el error y quede bloqueado en este estado, hasta el reset
- [ ] Agrega un recorte de la imagen del diagrama de estado en el repo en lugar de este ejemplo (si es necesario edita el link)

![imagen](https://github.com/eceae/tp9-mef-cuad-Delellis777/assets/127500945/48a24d2d-fc25-4c44-9803-a2d670f358ba)
:)

- [ ] al terminar esta parte identifícalo con commit: `punto1 listo`

## 2. Detección del estado inicial de los sensores :checkered_flag::arrow_right::gear:
- [ ] Modifica la maquina de estado del punto anterior y documenta la representación del diagrama de estados en `punto2.pdf` para que:
- [ ] Agregando un estado inicial adicional detecte ahora el nivel en el que están los sensores al comienzo e inmediatamente pase al estado que corresponde
- [ ] También realiza las modificaciones necesarias para que pueda salir del estado de detección de error al presionar la tecla 4:four: (con etiqueta `PIN_TEC4`) sin necesidad de esperar el reset, apagando tosdos los leds y pasando al estado que corresponde según el nivel de los sensores (puedes aprovechar para esto el estado creado en el punto anterior)
- [ ] Agrega un recorte de la imagen del diagrama de estado en el repo en lugar de este ejemplo (si es necesario edita el link)

![imagen](/digrama2.png)

# Documenta! :joy:

![imagen](https://user-images.githubusercontent.com/64550311/128095519-8ad1dbae-ce3b-442e-a2f3-b57ce8c9f9fd.png)


