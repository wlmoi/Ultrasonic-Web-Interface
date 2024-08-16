// client.js
async function fetchDistance() {
    try {
        const response = await fetch('/api/distance');
        const data = await response.json();
        document.getElementById('distance').textContent = `Distance: ${data.distance}`;
    } catch (error) {
        console.error('Error fetching distance:', error);
        document.getElementById('distance').textContent = 'Error fetching distance';
    }
}

// Fetch distance data every 2 seconds
setInterval(fetchDistance, 2000);
