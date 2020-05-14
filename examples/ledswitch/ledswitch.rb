val = 0
portled = 64
portsw = 33

pin_mode(portsw, 0);

while true
  if val == 1
    val = 0
  else
    val = 1
  end

  if digital_read(portsw) == 0
    portled += 1
    if portled > 67
      break
    end
  end

  digital_write(portled, val)
  sleep 1
end
