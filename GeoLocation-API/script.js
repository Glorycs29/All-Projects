var x = document.getElementById("demo");

function getLocation() {
  if (navigator.geolocation) {
    navigator.geolocation.getCurrentPosition(showPosition, showError);
  } else { 
    x.innerHTML = "Geolocation is not supported by this browser.";
  }
}

function showPosition(position) {
  const userLatitude = position.coords.latitude;
  const userLongitude = position.coords.longitude;

  // Send a request to the backend to get the nearest shop
  fetch('http://localhost:3000/nearestShop', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({ userLatitude, userLongitude })
  })
  .then(response => response.json())
  .then(data => {
    const nearestShop = data.nearestShop;
    if (nearestShop) {
      x.innerHTML = `Nearest Shop: ${nearestShop.name}`;
    } else {
      x.innerHTML = "No shops found.";
    }
  })
  .catch(error => {
    console.error('Error:', error);
    x.innerHTML = "An error occurred while fetching data.";
  });
}

function showError(error) {
  switch(error.code) {
    case error.PERMISSION_DENIED:
      x.innerHTML = "User denied the request for Geolocation."
      break;
    case error.POSITION_UNAVAILABLE:
      x.innerHTML = "Location information is unavailable."
      break;
    case error.TIMEOUT:
      x.innerHTML = "The request to get user location timed out."
      break;
    case error.UNKNOWN_ERROR:
      x.innerHTML = "An unknown error occurred."
      break;
  }
}
