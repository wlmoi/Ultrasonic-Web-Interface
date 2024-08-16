const apiEndpoint = 'backend/index.js';

async function getDistance() {
    try {
        const response = await fetch(apiEndpoint);
        const data = await response.json();
        document.getElementById('distance').innerText = data.distance;

        if (data.distance < 20) {
            document.getElementById('status').innerText = "Sebentar Lagi Penuh!";
        } else {
            document.getElementById('status').innerText = "Masih Ada Ruang";
        }
    } catch (error) {
        console.error('Error fetching distance:', error);
        document.getElementById('status').innerText = "Error fetching data!";
    }
}

setInterval(getDistance, 1000);
